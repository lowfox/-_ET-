#include "SeesawScene2019Logic.h"
#include <Logger.h>
#include <RyujiEv3.h>
SeesawScene2019Logic::SeesawScene2019Logic(Seesaw2019Param* param) {
  EV3_LOG_INFO("SeesawScene2019Logic Start !\n");
  m_param = param;
}

bool SeesawScene2019Logic::init() {
  EV3_LOG_DEBUG("SeesawScene2019Logic::init() Start !\n");
  EV3_LOG_DEBUG("SeesawScene2019Logic::init() End!\n");
  return true;
}

bool SeesawScene2019Logic::run() {
  EV3_LOG_DEBUG("SeesawScene2019Logic::run() Start !\n");
  EV3_LOG_DEBUG("SeesawScene2019Logic::run() End!\n");
  return true;
}
SeesawScene2019Logic::~SeesawScene2019Logic() {
  EV3_LOG_INFO("SeesawScene2019Logic End !\n");
}