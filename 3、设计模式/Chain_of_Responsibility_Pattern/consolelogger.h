#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "loggerchain.h"


typedef struct _console_logger{
    LoggerChain logger;
}Console_Logger;

Console_Logger *CreateConsoleLogger(int level);

#endif // CONSOLELOGGER_H
