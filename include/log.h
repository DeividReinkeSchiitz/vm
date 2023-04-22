//
// Created by deivid on 1/14/23.
//

#pragma once

#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define NUM_ARGS_STR(...) (sizeof((char *[]){__VA_ARGS__}) / sizeof(char *))

#define log_msg(type, message, ...) \
    LOG_MSG(type, __FILE__, __func__, __LINE__, message, ##__VA_ARGS__)

/**
 * @brief Types of logs messages.
 */
typedef enum LOG_TYPE
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR,
    LOG_DEBUG
} LOG_TYPE;

/**
 * @brief Attach a message inside the log_file.
 * @param log_file The log file.
 * @param message The message to be attached.
 * @param type The type of the message.
 * @Note The log file must be inside /root/logs.
 */
void LOG_MSG(LOG_TYPE type, char *exec_file_func, const char *exec_func, int exec_line, char *message, ...);

void get_exec_name(char name[NAME_MAX]);