#include "CompleteGarage.h"
CompleteGarage::CompleteGarage(Garage2019Param* param) {
  EV3_LOG_INFO("CompleteGarage start !\n");
  m_param                    = param;
  m_gLineTrace               = new GarageLineTrace;
  m_recognizeCurrentRocation = new RecognizeCurrentRocation(m_param);
}

bool CompleteGarage::run() {
  EV3_LOG_DEBUG("CompleteGarage::run start !\n");
  if (moveBlueLine() == false) {
    EV3_LOG_ERROR("CompleteGarage::moveBlueLine()");
    return false;
  }
  if (moveBlackLine() == false) {
    EV3_LOG_ERROR("CompleteGarage::moveBlackLine()");
    return false;
  }
  if (moveGarage() == false) {
    EV3_LOG_ERROR("CompleteGarage::moveGarage()");
    return false;
  }
  return true;
}

bool CompleteGarage::moveBlueLine() {
  EV3_LOG_DEBUG("CompleteGarage::moveBlueLine start !\n");
  // debug----
  RyujiEv3Engine::GetTailMotor()->setCounts(83, 20, true);
  dly_tsk(3000);
  //---------
  m_gLineTrace->configTraceColor(m_param->area1CurrentColor);
  m_gLineTrace->configTraceAngle(m_param->traceAngle);
  m_gLineTrace->configPID(m_param->area1Config.pid);
  m_gLineTrace->Drive(m_param->area1Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation(1) == false) {
  }

  return true;
}

bool CompleteGarage::moveBlackLine() {
  EV3_LOG_DEBUG("CompleteGarage::moveBlackLine start !\n");
  m_gLineTrace->configTraceColor(m_param->area2CurrentColor);
  m_gLineTrace->configTraceAngle(m_param->traceAngle);
  m_gLineTrace->configPID(m_param->area2Config.pid);
  m_gLineTrace->Drive(m_param->area2Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation(2) == false) {
  }
  return true;
}

bool CompleteGarage::moveGarage() {
  EV3_LOG_DEBUG("CompleteGarage::moveGarage start !\n");
  Steering::ResetDistance();
  m_gLineTrace->configTraceColor(m_param->area3CurrentColor);
  m_gLineTrace->configTraceAngle(m_param->traceAngle);
  m_gLineTrace->configPID(m_param->area3Config.pid);
  m_gLineTrace->Drive(m_param->area3Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation(3) == false) {
  }
  m_gLineTrace->stop();
  return true;
}

bool CompleteGarage::endDelete() {
  EV3_LOG_DEBUG("CompleteGarage::endDelete start !\n");
  delete m_gLineTrace;
  delete m_recognizeCurrentRocation;
  return true;
}

CompleteGarage::~CompleteGarage() {
  EV3_LOG_INFO("CompleteGarage end !\n");
  endDelete();
}