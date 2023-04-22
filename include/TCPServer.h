#pragma once

#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "sllist.h"

#define DEFAULT_PORT 12345
#define BUFFER_LENGTH 1024
#define MAX_QUEUE 8

/**
 * @brief Create a socket and bind it to a port.
 * @param sd The server socket descriptor.
 * @param serveraddr The server address.
 * @param port The port to bind. If 0, the default port (12345) is used.
 */
void sconnect(int *sd, struct sockaddr_in6 *serveraddr, int port);  // socket connection

/**
 * @brief Receive data from.
 * @param sd The server socket descriptor.
 * @param sd2 The client socket descriptor.
 * @param buffer The buffer to store the data.
 */
char *recvdata(int sd2);  // receive data

/**
 * @brief Send a response to the client.
 * @param sd The server socket descriptor.
 * @param sd2 The client socket descriptor.
 * @param res The response to send.
 */
void sendres(int sd, int sd2, const char *res);

/**
 * @brief Accept a connection.
 * @param sd The server socket descriptor.
 * @param sd2 The client socket descriptor.
 * @param peeraddr The client address.
 */
void acceptconn(int sd, int *sd2, struct sockaddr_in6 *peeraddr);

/**
 * @brief Close the connection.
 * @param sd The server socket descriptor.
 * @param sd2 The client socket descriptor.
 * @param ipstr The ip address of the client.
 * @param peeraddr The client address.
 */
void clientip(int sd, int sd2, char *ipstr, struct sockaddr_in6 peeraddr);

/**
 * @brief Get header element value from element.
 * @param header The header buffer to search.
 * @param h_elem The header element to find value.
 * @return The value of the header element.
 */
char *get_header_value(const char *header, char *h_elem);