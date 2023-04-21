//
// Created by deivid on 11/28/22.
//

#include "TCPServer.h"

void sconnect(int *sd, struct sockaddr_in6 *serveraddr, int port)
{
    ssize_t rc = 1;
    int on     = 1;
    // create a socket
    *sd        = socket(AF_INET6, SOCK_STREAM, 0);

    if (*sd < 0)
        log_msg(LOG_ERROR, "socket creation failed.");

    rc = setsockopt(*sd, SOL_SOCKET, SO_REUSEADDR,
                    (char *) &on, sizeof(on));
    if (rc < 0)
        log_msg(LOG_ERROR, "setsockopt() failed");

    // AF_INET6 address family
    serveraddr->sin6_family   = AF_INET6;
    serveraddr->sin6_port     = htons(port | DEFAULT_PORT);
    serveraddr->sin6_flowinfo = 0;
    serveraddr->sin6_addr     = in6addr_any;
    serveraddr->sin6_scope_id = 0;

    // bind the socket to the server address
    rc                        = bind(*sd, (struct sockaddr *) serveraddr,
                                     sizeof(struct sockaddr_in6));
    if (rc < 0)
        log_msg(LOG_ERROR, "bind() failed.");

    // listen for connections
    rc = listen(*sd, MAX_QUEUE);
    if (rc < 0)
        log_msg(LOG_ERROR, "listen() failed.");
}

char *recvdata(int sd2)
{
    /*
     * The response must hava a Content-Length header or
     * a (TODO) Transfer-Encoding header with the value chunked to the
     * server know when the response is finished.
     * */

    char *content_lenght_str   = "";
    char *break_point          = "";
    char *content_length_el    = "Content-Length";
    char buffer[BUFFER_LENGTH] = "";
    SLList *data_rcvd          = sllist_mk();

    int content_length         = 0;

    ssize_t rc                 = 1;

    // clear the buffer
    if (sllist_ismpty(data_rcvd))
        sllist_clear(data_rcvd);

    /*
     * First receives the request from the client to get
     * the Content-Length header value.
     */
    while (1)
    {
        bzero(buffer, BUFFER_LENGTH);
        rc = recvfrom(sd2, buffer, BUFFER_LENGTH - 1, 0,
                      NULL, NULL);

        if (rc < 0)
            log_msg(LOG_ERROR, "recvfrom() failed.");

        if (rc == 0)
            log_msg(LOG_ERROR, "Client closed connection.");

        sllist_push(data_rcvd, buffer, rc);

        // Stop receiving when the connection is closed or
        //        break_point = strstr(buffer, "Connection: close");
        //        if (break_point != NULL)
        //            break;

        // Stop receiving when the \r\n is found.
        break_point = strstr(buffer, "\r\n\r\n");
        if (break_point != NULL)
        {
            break_point += sizeof("\r\n\r\n") - 1;
            break;
        }
    }

    // Get the Content-Length header value.
    content_lenght_str = get_header_value(buffer, content_length_el);
    if (content_lenght_str == NULL)
    {
        char *d_str = sllist_2str(data_rcvd);

        sllist_free(data_rcvd);
        free(content_lenght_str);
        return d_str;
    }
    // convert the Content-Length value to int.
    content_length        = (int) strtoll(content_lenght_str, NULL, 10);

    // Get the size of the data_rcvd remaining to receive.
    size_t cont_remaining = content_length - rc + (break_point - buffer);

    char tmp_buffer[cont_remaining];

    /*
     * Set socket options to receive the remaining data_rcvd.
     * The optname SO_RCVLOWAT sets the minimum number of bytes to
     * receive before the recv() call returns.
     */
    rc = setsockopt(sd2, SOL_SOCKET, SO_RCVLOWAT, &cont_remaining,
                    sizeof(cont_remaining));

    if (rc < 0)
        log_msg(LOG_ERROR, "setsockopt(SO_RCVLOWAT) failed.");

    // Receive the remaining data_rcvd.
    rc = recvfrom(sd2, tmp_buffer, cont_remaining, 0,
                  NULL, NULL);

    if (rc < 0 || rc < sizeof(tmp_buffer))
        log_msg(LOG_ERROR, "Client closed connection.");

    tmp_buffer[rc] = '\0';

    // Add the remaining data_rcvd to the list.
    sllist_push(data_rcvd, tmp_buffer, rc);

    char *d_str = sllist_2str(data_rcvd);

    sllist_free(data_rcvd);
    free(content_lenght_str);

    return d_str;
}

void sendres(int sd, int sd2, const char *res)
{
    ssize_t rc = 1;

    rc         = send(sd2, res, strlen(res), 0);

    if (rc < 0)
        log_msg(LOG_ERROR, "send() failed.");
}

void acceptconn(int sd, int *sd2, struct sockaddr_in6 *peeraddr)
{
    socklen_t addr_size = sizeof(struct sockaddr_in6);
    *sd2                = accept(sd, (struct sockaddr *) peeraddr, &addr_size);
    if (*sd2 < 0)
        log_msg(LOG_ERROR, "accept() failed.");
}

void clientip(int sd, int sd2, char *ipstr, struct sockaddr_in6 peeraddr)
{
    int rc        = 1;
    socklen_t len = sizeof(struct sockaddr_in6);
    rc            = getpeername(sd2, (struct sockaddr *) &peeraddr, &len);

    if (rc < 0)
        log_msg(LOG_ERROR, "getpeername() failed.");

    // convert the IP address to a string
    inet_ntop(AF_INET6, &peeraddr.sin6_addr, ipstr, sizeof(ipstr));

    printf("Peer IP address: %s\n", ipstr);
    printf("Peer port: %d\n", ntohs(peeraddr.sin6_port));
}

char *get_header_value(const char *header, char *h_elem)
{
    int i            = 0;

    // if the header element is not found
    char *h_elem_ptr = strstr(header, h_elem);
    if (h_elem_ptr == NULL)
        return NULL;

    // get first position of Content-Length in header
    size_t pos = h_elem_ptr - header + strlen(h_elem) + 2;

    while (header[pos + i] != '\r') i++;

    char *elem_val = (char *) malloc(i + 1);
    if (elem_val == NULL)
        log_msg(LOG_ERROR, "Singly Linked List Overflow");

    strncpy(elem_val, header + pos, i);
    elem_val[i] = '\0';

    return elem_val;
}
