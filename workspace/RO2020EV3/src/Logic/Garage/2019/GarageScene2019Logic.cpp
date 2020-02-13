#include "GarageScene2019Logic.h"
#include <RyujiEv3.h>
#include <Logger.h>
GarageScene2019Logic::GarageScene2019Logic(Garage2019Param* param) {
  EV3_LOG_INFO("GarageScene2019Logic Start !\n");
  m_param = param;
  for (int i = 0; i < m_param->distance; i++) {
  }
}

bool GarageScene2019Logic::init() { return true; }

bool GarageScene2019Logic::run() {
  RyujiEv3Engine::GetLCD()->drawString(20, 20, "HELLO EV3!\n");
  RyujiEv3Engine::GetSpeaker()->setVolume(50);
  RyujiEv3Engine::GetSpeaker()->playTone(50, 500);
  EV3_LOG_INFO("GarageScene2019Logic END !\n");
  return true;
}
