#ifndef ESTDLIB_LOGGER
#define ESTDLIB_LOGGER

typedef struct logger logger;
typedef enum riskLevel
{
    LOW,
    MEDIUM,
    HIGH,
    FATAL
}riskLevel;

logger *ESTDLIB_newLogger(const char * path);
void ESTDLIB_dropLogger(logger *lg);
int ESTDLIB_log(logger *lg, riskLevel risk, const char *data);

#endif
