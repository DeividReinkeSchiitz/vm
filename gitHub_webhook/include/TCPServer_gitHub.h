//
// Created by deivid on 12/7/22.
//

#pragma once

#include "JSON.h"
#include "TCPServer.h"
#include "hmac.h"

/**
 * Data structure for the github server
 */


typedef struct Github_Req
{
    /**
     * The github will send a request a header and a body_str
     * separated by a "\r\n\r\n".
     */
    char *header;
    char *body_str;

    JSON_list *body_jsn;

    /**
     * Header fields
     */
    char *method;
    char *path;
    char *version;
    char *host;
    char *user_agent;
    char *content_length;
    char *accept;
    char *x_gitHub_delivery;
    char *x_gitHub_event;
    char *x_gitHub_hook_id;
    char *x_gitHub_hook_installation_target_id;
    char *x_gitHub_hook_installation_target_type;
    char *x_hub_signature_256;
    char *content_type;
    char *connection;
} Github_Req;

/**
 * Threat the github request
 * @param buffer
 * @param g_req
 * @return void
 */
static void github_req(char *buffer, Github_Req *g_req);

/**
 * Main function for the github server
 * @return void
 */
_Noreturn void github_server();

/**
 * Check the signature of the github request
 * @param g_req The github request
 * @param repo_name The key to check the signature
 * @return void
 * @note The repo_name is the name of the repository that is going to be checked
 * inside gitHub_webhook.cfg file
 */
static void check_signature(Github_Req *g_req, char *repo_name);

/**
 * Get the webhook secret from the config file
 * @param secret to store the secret
 * @param repo_name to search the secret
 * @return void
 * @note The repo_name MUST exist inside .cfg file
 */
static void get_webhook_secret(char *secret, char *repo_name);

/**
 * Free the memory allocated for the Github_Req structure
 * @param g_req
 * @return void
 */
static void free_greq(Github_Req *g_req);