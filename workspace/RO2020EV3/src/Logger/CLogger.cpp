#include "ev3api.h"
#include "CLogger.h"

static const char* levelString[] = {"[error]", "[info]", "[app]", "[debug]"};
CLogger* CLogger::m_instance     = nullptr;

CLogger::CLogger() {}

CLogger::~CLogger() {}

void CLogger::writeLog(LogDesc desc, const char* log) {
  loc_mtx(LOG_MTX);

  if (checkLevel(desc)) {
    auto* bluetooth = RyujiEv3Engine::GetBluetooth();

    bluetooth->writeString("%-8s", levelString[static_cast<int32>(desc)]);
    bluetooth->writeString(log);
  }

  unl_mtx(LOG_MTX);
}

void CLogger::setOutLevel(LogOutLevel outLevel) {
  loc_mtx(LOG_MTX);

  m_outLevel = outLevel;

  unl_mtx(LOG_MTX);
}

bool CLogger::checkLevel(LogDesc desc) {
  if (m_outLevel == LogOutLevel::All) {
    return true;
  } else if (m_outLevel == LogOutLevel::Nomal) {
    return desc < LogDesc::Debug;
  } else if (m_outLevel == LogOutLevel::Error) {
    return desc < LogDesc::Info;
  }
  return false;
}
