#include "logger.h"

static Logger *logger;

Logger *get_logger() { return logger; }

const char *get_current_datetime() {
    static char time_string[20];
    time_t current_time;
    struct tm *time_info;

    time(&current_time);
    time_info = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    return time_string;
}

Logger *log_init(const char *name_file, enum log_level level) {
    logger = (Logger *)malloc(sizeof(Logger));
    if (!logger) return NULL;

    logger->log_file = fopen(name_file, "w");

    if (!(logger->log_file)) {
        free(logger);
        return NULL;
    }

    logger->current_level = level;
    return logger;
}

void logcat(enum log_level level, const char *format, ...) {
    const char *current_datetime = get_current_datetime();
    const char *level_strings[] = {"DEBUG", "TRACE", "INFO", "WARNING", "ERROR"};

    va_list args;
    va_start(args, format);

    fprintf(logger->log_file, "[%s] %s ", current_datetime, level_strings[level]);
    vfprintf(logger->log_file, format, args);
    fprintf(logger->log_file, "\n");
    fflush(logger->log_file);

    va_end(args);
}

void logclose() {
    if (logger) {
        if (logger->log_file) fclose(logger->log_file);
        free(logger);
    }
}