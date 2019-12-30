#ifndef LOGGERCHAIN_H
#define LOGGERCHAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFO  1
#define DEBUG 2
#define ERROR 3

typedef void (*set_next_logger_func)(void *this_logger,void *next_logger);
typedef void (*logger_msg_func)(void *this_logger,int level,const char *msg);
typedef void (*write_func)(void *this_logger,const char *msg);
typedef struct _LoggerChain{
    int level;
    struct _LoggerChain *nextLogger;
    set_next_logger_func set_next_logger;
    logger_msg_func      logger_msg;
    write_func           write;
}LoggerChain;

int CreateLoggerChain(LoggerChain *logger, int level);

#endif // LOGGERCHAIN_H
