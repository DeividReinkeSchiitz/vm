//
// Created by deivid on 11/25/22.
//

#include "rwe.h"

void *exec(const char *command, SLList *result)
{
    FILE *fp;
    char path[1024];
    int status;

    /* Open the command for reading. */
    fp = popen(command, "r");
    if (fp == NULL)
        log_msg(LOG_ERROR, "Failed to run command\n");

    /* Read the output a line at a time - output it. */;
    while (fgets(path, sizeof(path) - 1, fp) != NULL)
    {
        // concat path and result
        sllist_push(result, path, sizeof(path) - 1);
    }

    /* close and free */
    status = pclose(fp);

    if (status == -1)
        log_msg(LOG_ERROR, "Failed to run command\n");
}

void writeF(const char *fileName, const char *command)
{
    FILE *fp;

    /* Open the command for write. */
    fp = fopen(fileName, "w");
    if (fp == NULL)
        log_msg(LOG_ERROR, "Failed to run command\n");

    /* write in the file */
    fprintf(fp, "%s", command);

    /* close and free */
    fclose(fp);
}


void readF(const char *fileName, SLList *result)
{
    FILE *fp;
    char path[1024];

    /* Open the command for reading. */
    fp = fopen(fileName, "r");
    if (!fp)
        log_msg(LOG_ERROR, "Failed to run command\n");

    /* Read the output a line at a time - output it. */;
    while (fgets(path, sizeof(path) - 1, fp) != NULL)
    {
        // concat path and result
        sllist_push(result, path, sizeof(path) - 1);
    }

    /* close and free */
    fclose(fp);
}
