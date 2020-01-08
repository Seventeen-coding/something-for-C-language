
#include "chain_of_responsibility_pattern.h"
#include <stdio.h>

void run();

int main(void)
{
    run();
    return 0;
}

//test
void run()
{
    LoggerChain *headlogger;
    LoggerChain *errorLogger = (LoggerChain *)CreateErrorLogger(ERROR);
    LoggerChain *fileLogger = (LoggerChain *)CreateFileLogger(DEBUG);
    LoggerChain *consoleLogger = (LoggerChain *)CreateConsoleLogger(INFO);

    if (errorLogger == NULL || fileLogger == NULL || consoleLogger == NULL)
    {
        return;
    }
    errorLogger->set_next_logger(errorLogger, fileLogger);
    fileLogger->set_next_logger(fileLogger, consoleLogger);

    headlogger = errorLogger;

    headlogger->logger_msg(headlogger, INFO, "This is an information.");
    printf("\n");
    headlogger->logger_msg(headlogger, DEBUG, "This is an debug level information.");
    printf("\n");
    headlogger->logger_msg(headlogger, ERROR, "This is an error information.");
    printf("\n");
}
