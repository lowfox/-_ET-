#include "GarageScene2019Logic.h"
#include <RyujiEv3.h>
#include <Logger.h>
GarageScene2019Logic::GarageScene2019Logic(Garage2019Param* param) {
  EV3_LOG_INFO("GarageScene2019Logic Start !\n");
  m_param = param;
  for (int i = 0; i < m_param->distance; i++) {
  }
}

bool GarageScene2019Logic::init() {
  EV3_LOG_DEBUG("GarageScene2019Logic::init() Start !\n");
  EV3_LOG_DEBUG("GarageScene2019Logic::init() End!\n");
  return true;
}

bool GarageScene2019Logic::run() {
  EV3_LOG_INFO("GarageScene2019Logic::run() Start !\n");
  EV3_LOG_INFO("GarageScene2019Logic::run() END !\n");
  return true;
}
GarageScene2019Logic::~GarageScene2019Logic() {
  EV3_LOG_INFO("GarageScene2019Logic End ! \n");
}