#include "GarageScene2019Logic.h"
#include <RyujiEv3.h>
#include <Logger.h>

GarageScene2019Logic::GarageScene2019Logic(Garage2019Param* param) {
  EV3_LOG_INFO("GarageScene2019Logic Start !\n");
  m_param = param;
}

bool GarageScene2019Logic::init() {
  EV3_LOG_DEBUG("GarageScene2019Logic::init() Start !\n");
  EV3_LOG_DEBUG("GarageScene2019Logic::init() End!\n");
  return true;
}

bool GarageScene2019Logic::run() {
  EV3_LOG_INFO("GarageScene2019Logic::run() Start !\n");
  RyujiEv3Engine::GetRightMotor()->setCounts(m_param->distance, m_param->ii,
                                             true);
  EV3_LOG_INFO("GarageScene2019Logic::run() END !\n");
  return true;
}

GarageScene2019Logic::~GarageScene2019Logic() {
  EV3_LOG_INFO("GarageScene2019Logic End ! \n");
}