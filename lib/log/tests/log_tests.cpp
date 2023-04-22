//
// Created by deivid on 1/30/23.
//

extern "C"
{
#include "log.h"
}

#include <fstream>
#include <gtest/gtest.h>
#include <iostream>

// get current path
extern char LOG_FOLDER[200];


TEST(LogTest, LogTest)
{
    std::string currentLogFile = __FILE__;
    // remove the last part of the path
    currentLogFile             = currentLogFile.substr(0, currentLogFile.find_last_of("/"));
    currentLogFile += "/";

    // change the current log file
    strcpy(LOG_FOLDER, currentLogFile.c_str());

    log_msg(LOG_INFO, (char *) "This is a test message");

    // check if a file named __FILE__.log exist
    std::string logFile = currentLogFile + __FILE_NAME__;
    logFile             = logFile.substr(0, logFile.find_last_of(".")) + ".log";

    std::ifstream file(logFile.c_str());
    EXPECT_TRUE(file.good());

    // read from file
    std::string line;
    std::getline(file, line);

    // check if the message contain the test message
    EXPECT_TRUE(line.find("This is a test messageee") != std::string::npos);

    // remove the log file and close
    file.close();
    remove(logFile.c_str());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}