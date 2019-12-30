#include "filelogger.h"

static void _write(File_Logger *this_logger,const char *msg);

File_Logger *CreateFileLogger(int level)
{
    File_Logger *logger;
    logger = ( File_Logger * ) malloc(sizeof(File_Logger));
    if(logger == NULL)
    {
        return NULL;
    }
    memset(logger, 0 , sizeof(File_Logger));
    do
    {
        if(CreateLoggerChain(&logger->logger,level) != 0)   break;
        logger->logger.write = _write;
        return logger;
    }while(0);
    free (logger);

    return NULL;
}

void _write(File_Logger *this_logger,const char *msg)
{
    if(this_logger == NULL || msg == NULL)
    {
        return;
    }
    printf("File::Logger: %s \n",msg);
}

