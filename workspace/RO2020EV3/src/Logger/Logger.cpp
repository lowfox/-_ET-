#include <Logger.h>
#include "CLogger.h"
#include <cstdarg>

namespace Logger {
void WriteLog(LogDesc desc, const char* format, ...) {
  va_list args;
  char log[MAX_LOG_LENGTH];
  char logBuf[MAX_LOG_LENGTH];

  va_start(args, format);
  vsprintf(log, format, args);
  va_end(args);
  sprintf(logBuf, "%s\n", log);
  CLogger::GetInstance()->writeLog(desc, logBuf);
}

void SetOutLevel(LogOutLevel outLevel) {
  CLogger::GetInstance()->setOutLevel(outLevel);
}
}  // namespace Logger