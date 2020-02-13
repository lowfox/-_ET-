#include "SeesawScene2019Logic.h"
#include <Logger.h>
SeesawScene2019Logic::SeesawScene2019Logic(Seesaw2019Param* param) {
  EV3_LOG_INFO("SeesawScene2019Logic Start !\n");
  m_param = param;
}

bool SeesawScene2019Logic::init() { return true; }

bool SeesawScene2019Logic::run() {
  EV3_LOG_INFO("SeesawScene2019Logic End !\n");
  return true;
}