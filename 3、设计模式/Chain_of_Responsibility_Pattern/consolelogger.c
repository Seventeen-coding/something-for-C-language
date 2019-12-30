#include "consolelogger.h"

static void _write(Console_Logger *this_logger,const char *msg);

Console_Logger *CreateConsoleLogger(int level)
{
    Console_Logger *logger;
    logger = ( Console_Logger * ) malloc(sizeof(Console_Logger));
    if(logger == NULL)
    {
        return NULL;
    }
    memset(logger, 0 , sizeof(Console_Logger));
    do
    {
        if(CreateLoggerChain(&logger->logger,level) != 0)   break;

        logger->logger.write = _write;
        return logger;
    }while(0);
    free (logger);

    return NULL;
}

void _write(Console_Logger *this_logger,const char *msg)
{
    if(this_logger == NULL || msg == NULL)
    {
        return;
    }
    printf("Standard Console::Logger: %s \n",msg);
}
