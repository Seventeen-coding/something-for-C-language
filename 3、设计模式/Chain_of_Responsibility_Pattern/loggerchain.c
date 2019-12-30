#include "loggerchain.h"

static void set_next_logger(LoggerChain *this_logger,LoggerChain *next_logger);
static void logger_msg(LoggerChain *this_logger,int level,const char *msg);

int CreateLoggerChain(LoggerChain *logger,int level)
{
    if(logger == NULL)
    {
        return -1;
    }
    memset(logger, 0 , sizeof(LoggerChain));
    logger->logger_msg = logger_msg;
    logger->set_next_logger = set_next_logger;
    logger->level = level;
    return 0;
}

static void set_next_logger(LoggerChain *this_logger,LoggerChain *next_logger)
{
    if(this_logger == NULL || next_logger == NULL )
    {
        return ;
    }

    this_logger->nextLogger = next_logger;
}


static void logger_msg(LoggerChain *this_logger,int level,const char *msg)
{
    if(this_logger == NULL || msg == NULL )
    {
        return;
    }

    if(this_logger->level <= level){
        if( this_logger->write != NULL)
        {
            this_logger->write(this_logger,msg);
        }
    }

    if(this_logger->nextLogger != NULL){
        this_logger->nextLogger->logger_msg(this_logger->nextLogger,level, msg);
    }
}
