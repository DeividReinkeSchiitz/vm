//
// Created by deivid on 1/14/23.
//

#include "log.h"

char LOG_FOLDER[200] = "/HD/Source/vm/logs/";
#define printerr(...) fprintf(stderr, __VA_ARGS__)

static const char *LOG_TYPE_STR[] =
        {
                [LOG_INFO]    = "INFO",
                [LOG_WARNING] = "WARNING",
                [LOG_ERROR]   = "ERROR",
                [LOG_DEBUG]   = "DEBUG"};

static void get_formatted_time(char time_str[20])
{
    time_t current_time  = time(NULL);                //get current time
    struct tm *time_info = localtime(&current_time);  //convert time to struct tm
    char buffer[20];
    // format the time as "YYYY-MM-DD HH:MM:SS"
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", time_info);

    strcpy(time_str, buffer);
}

void get_exec_name(char name[NAME_MAX])
{
    char exe_path[PATH_MAX];

    char *exe_name, *base_name;
    pid_t pid = getpid();
    sprintf(exe_path, "/proc/%d/exe", pid);
    exe_name = realpath(exe_path, NULL);
    if (exe_name == NULL)
    {
        perror("realpath");
        exit(1);
    }
    base_name = strrchr(exe_name, '/');
    if (base_name == NULL)
    {
        base_name = exe_name;
    }
    else
    {
        base_name++;
    }

    strcpy(name, base_name);
    free(exe_name);
}

void LOG_MSG(LOG_TYPE type, char *exec_file_func, const char *exec_func, int exec_line, char *message, ...)
{
    char log_name[PATH_MAX];
    char time[20];
    char exec_name[NAME_MAX];

    bzero(log_name, 100);

    // Write the message in the log file
    get_formatted_time(time);

    // Get the executable name
    get_exec_name(exec_name);

    va_list args;
    va_start(args, message);

    strcat(log_name, LOG_FOLDER);
    strcat(log_name, exec_name);
    strcat(log_name, ".log");


    // Open the log file and create it if it doesn't exist
    FILE *FILE_lname = fopen(log_name, "a");
    if (FILE_lname == NULL)
        printerr("LOG_MSG. Error opening file: %s", log_name);

    fprintf(FILE_lname, "[%s] %s ", LOG_TYPE_STR[type], time);
    vfprintf(FILE_lname, message, args);

    if (type == LOG_ERROR)
    {
        fprintf(FILE_lname, " - (%s, %s): %d -- %s",
                exec_file_func, exec_func, exec_line, strerror(errno));
    }

    fprintf(FILE_lname, "\r\n");

    va_end(args);

    fclose(FILE_lname);
}
