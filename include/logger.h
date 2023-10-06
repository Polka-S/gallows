#ifndef LOGGER_H
#define LOGGER_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "log_levels.h"

typedef struct {
    FILE *log_file;
    enum log_level current_level;
} Logger;

Logger *log_init(const char *name_file, enum log_level level);

void logcat(enum log_level level, const char *format, ...);

void logclose();

#endif  // LOGGER_H