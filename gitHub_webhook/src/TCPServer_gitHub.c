//
// Created by deivid on 12/7/22.
//

#include "TCPServer_gitHub.h"

#define SERVER_PORT 12345
#define LOG_FILE "gitHub_webhook.log"

_Noreturn void github_server()
{
    int sd                          = -1;
    int sd2                         = -1;

    struct sockaddr_in6 server_addr = {0};
    struct sockaddr_in6 peer_addr   = {0};
    char *data_rcvd                 = "";
    Github_Req *g_req               = (Github_Req *) malloc(sizeof(Github_Req) + 1);

    const char *res                 = "HTTP/1.1 200 OK\n"
                                      "Content-Type: text/plain\n\n"
                                      "Server response\n";

    // socket connection
    sconnect(&sd, &server_addr, SERVER_PORT);

    // listen
    while (1)
    {
        // accept connection
        acceptconn(sd, &sd2, &peer_addr);

        // read from the socket
        data_rcvd = recvdata(sd2);


        if (data_rcvd != NULL)
        {
            // threat the request
            github_req(data_rcvd, g_req);

            char *repo_name = JSON_get(g_req->body_jsn, "repository", "name");
            printf("Repository name: %s\n", repo_name);

            // Check signature. Is not necessary if the GitHub ips is whitelisted
            if (g_req->x_hub_signature_256 == NULL)
            {
                res = "HTTP/1.1 400 OK\n"
                      "Content-Type: text/plain\n\n"
                      "No signature founded.\n";

                printf("No signature founded.\n");
            }
            else
                check_signature(g_req, repo_name);

            free(repo_name);
        }


        // send data to the client
        sendres(sd, sd2, res);

        // free and close
        free_greq(g_req);
        free(data_rcvd);
        close(sd2);
    }

    close(sd);
}

static void github_req(char *buffer, Github_Req *g_req)
{
    char *break_point = "";
    char *header_end  = "\r\n\r\n";
    char *tmp         = "";

    // get the header
    break_point       = strstr(buffer, header_end);
    g_req->header     = (char *) malloc((break_point - buffer) + 1);
    if (g_req->header == NULL)
        log_msg(LOG_ERROR, "Error allocating memory for the header.");
    bzero(g_req->header, (break_point - buffer) + 1);
    strncpy(g_req->header, buffer, break_point - buffer);


    // get the body_str
    g_req->body_str = (char *) malloc(strlen(buffer) - strlen(g_req->header) + 1);
    if (g_req->header == NULL)
        log_msg(LOG_ERROR, "Error allocating memory for the Body.");
    bzero(g_req->body_str, strlen(buffer) - strlen(g_req->header) + 1);
    strcpy(g_req->body_str, buffer + strlen(g_req->header) + strlen(header_end));

    // handle body_str into a JSON_list
    g_req->body_jsn = JSON_mk(JSON_OBJECT);
    JSON_parse(g_req->body_jsn, g_req->body_str);

    // get the header fields
    g_req->host                                   = get_header_value(buffer, "Host");
    g_req->user_agent                             = get_header_value(buffer, "User-Agent");
    g_req->content_length                         = get_header_value(buffer, "Content-Length");
    g_req->accept                                 = get_header_value(buffer, "Accept");
    g_req->x_gitHub_delivery                      = get_header_value(buffer, "X-GitHub-Delivery");
    g_req->x_gitHub_event                         = get_header_value(buffer, "X-GitHub-Event");
    g_req->x_gitHub_hook_id                       = get_header_value(buffer, "X-GitHub-Hook-Id");
    g_req->x_gitHub_hook_installation_target_id   = get_header_value(buffer, "X-GitHub-Hook-Installation-Target-ID");
    g_req->x_gitHub_hook_installation_target_type = get_header_value(buffer, "X-GitHub-Hook-Installation-Target-Type");
    g_req->x_hub_signature_256                    = get_header_value(buffer, "X-Hub-Signature-256");
    g_req->content_type                           = get_header_value(buffer, "Content-Type");
    g_req->connection                             = get_header_value(buffer, "Connection");

    tmp                                           = strtok(buffer, "\n");
    g_req->method                                 = strtok(tmp, " ");
    g_req->path                                   = strtok(NULL, " ");
    g_req->version                                = strtok(NULL, " ");
}

static void get_webhook_secret(char *secret, char *repo_name)
{
    FILE *fp;

    fp = fopen("/root/etc/gitHub_webhook.cfg", "r");
    if (!fp)
        log_msg(LOG_ERROR, "Error opening config file.");

    char format[100];
    bzero(format, 100);
    strcat(format, repo_name);
    strcat(format, "=%s");

    while (fscanf(fp, format, secret) != 0)
        ;

    fclose(fp);
}

static void check_signature(Github_Req *g_req, char *repo_name)
{

    char secret[100] = "";
    get_webhook_secret(secret, repo_name);

    char *body_signature = sha256_decode(g_req->body_str, secret);
    size_t body_slen     = strlen(body_signature);

    char body_cmp[body_slen + 8];
    bzero(body_cmp, body_slen + 8);

    strcat(body_cmp, "sha256=");
    strcat(body_cmp, body_signature);

    if (strcmp(body_cmp, g_req->x_hub_signature_256) != 0)
    {
        log_msg(LOG_ERROR, "Signature (%s) does not match with the body signature (%s)",
                g_req->x_hub_signature_256, body_cmp);
    }

    free(body_signature);
}

static void free_greq(Github_Req *g_req)
{
    free(g_req->header);
    free(g_req->body_str);

    free(g_req->host);
    free(g_req->user_agent);
    free(g_req->content_length);
    free(g_req->accept);
    free(g_req->x_gitHub_delivery);
    free(g_req->x_gitHub_event);
    free(g_req->x_gitHub_hook_id);
    free(g_req->x_gitHub_hook_installation_target_id);
    free(g_req->x_gitHub_hook_installation_target_type);
    free(g_req->x_hub_signature_256);
    free(g_req->content_type);
    free(g_req->connection);

    JSON_free(g_req->body_jsn);
    free(g_req);
}

static void github_ping()
{
}