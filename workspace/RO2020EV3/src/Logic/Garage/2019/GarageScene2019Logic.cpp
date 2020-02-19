#include "GarageScene2019Logic.h"

GarageScene2019Logic::GarageScene2019Logic(Garage2019Param* param) {
  EV3_LOG_INFO("GarageScene2019Logic Constractar  !\n");
  Steering::SetMode(SteeringMode::Nomal);
  m_param          = param;
  m_completeGarage = new CompleteGarage(param);
}

bool GarageScene2019Logic::init() {
  EV3_LOG_DEBUG("GarageScene2019Logic::init() Start !\n");

  EV3_LOG_DEBUG("GarageScene2019Logic::init() End!\n");

  return true;
}

bool GarageScene2019Logic::run() {
  EV3_LOG_INFO("GarageScene2019Logic::run() Start !\n");

  m_completeGarage->run();

  EV3_LOG_INFO("GarageScene2019Logic::run() END !\n");

  return true;
}

GarageScene2019Logic::~GarageScene2019Logic() {
  EV3_LOG_INFO("GarageScene2019Logic Detractar  ! \n");
  delete m_completeGarage;
}