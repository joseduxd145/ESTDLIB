#ifndef ESTDLIB_LOGGER
#define ESTDLIB_LOGGER

typedef struct ESTDLIB_logger logger;
typedef enum ESTDLIB_riskLevel
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
