#include "logger.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef struct ESTDLIB_logger
{
    const char *logFile;
    FILE *f;
}logger;

logger *ESTDLIB_newLogger(const char *path)
{
    if(!path)
    {
        return NULL;
    }

    logger *lg = malloc(sizeof(logger));
    if(!lg)
    {
        return NULL;
    }

    lg->logFile = path;
    lg->f = NULL;

    return lg;
}

void ESTDLIB_dropLogger(logger *lg)
{
    if(lg)
    {
        free(lg);
    }
}

int ESTDLIB_log(logger *lg, riskLevel risk, const char *data)
{
    if(!lg || !data)
    {
        return 1;
    }

    char *level = NULL;

    switch (risk)
    {
    case LOW:
        level = "[LOW]";
        break;
    case MEDIUM:
        level = "[MID]";
        break;
    case HIGH:
        level = "[HIGH]";
        break;
    case FATAL:
        level = "[FATAL]";
        break;
    }
    time_t now = time(NULL);
    char *fechaHora = asctime(localtime(&now));
    fechaHora[strlen(fechaHora) - 1] = '\t';

    lg->f = fopen(lg->logFile, "a");
    if(!lg->f)
    {
        return 2;
    }

    fprintf(lg->f, "%s\t%s%s\n", level, fechaHora, data);

    fclose(lg->f);
    return 0;
}
