#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "loggerchain.h"

typedef struct _file_logger{
    LoggerChain logger;
}File_Logger;

File_Logger *CreateFileLogger(int level);

#endif // FILELOGGER_H
