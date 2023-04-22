//
// Created by deivid on 11/25/22.
//

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "log.h"
#include "sllist.h"

/**
 * @brief Execute command in terminal and return the output
 * @param command
 * @return void
 */
void *exec(const char *command, SLList *result);

/**
 * @brief Write a command/message in a file
 * @param fileName
 * @param command
 * @return void
 */
void writeF(const char *fileName, const char *command);

/**
 * @brief Read a file
 * @param fileName
 * @return void
 */
void readF(const char *fileName, SLList *result);
