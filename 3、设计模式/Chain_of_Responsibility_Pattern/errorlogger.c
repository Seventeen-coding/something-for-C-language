#include "errorlogger.h"

static void _write(Error_Logger *this_logger,const char *msg);

Error_Logger *CreateErrorLogger(int level)
{
    Error_Logger *logger;
    logger = ( Error_Logger * ) malloc(sizeof(Error_Logger));
    if(logger == NULL)
    {
        return NULL;
    }
    memset(logger, 0 , sizeof(Error_Logger));
    do
    {
        if(CreateLoggerChain(&logger->logger,level) != 0)   break;
        logger->logger.write = _write;
        return logger;
    }while(0);
    free (logger);

    return NULL;
}

void _write(Error_Logger *this_logger,const char *msg)
{
    if(this_logger == NULL || msg == NULL)
    {
        return;
    }
    printf("Error Console::Logger:  %s \n",msg);
}

