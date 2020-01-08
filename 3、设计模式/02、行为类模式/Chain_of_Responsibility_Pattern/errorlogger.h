#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include "loggerchain.h"


typedef struct _error_logger{
    LoggerChain logger;
}Error_Logger;

Error_Logger *CreateErrorLogger(int level);

#endif // ERRORLOGGER_H
