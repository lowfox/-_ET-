#include "CompleteGarage.h"
#include <Logger.h>
CompleteGarage::CompleteGarage(Garage2019Param* param) {
  EV3_LOG_INFO("CompleteGarage start !\n");
  m_param                    = param;
  m_gLineTrace               = new GarageLineTrace;
  m_recognizeCurrentRocation = new RecognizeCurrentRocation(m_param);
}

bool CompleteGarage::run() {
  EV3_LOG_DEBUG("CompleteGarage::run start !\n");
  moveBlueLine();
  // moveBlackLine();
  // moveGarage();
  return true;
}

bool CompleteGarage::moveBlueLine() {
  // /* Debug
  RyujiEv3Engine::GetTailMotor()->setCounts(-3, 10, false);
  RyujiEv3Engine::GetTailMotor()->resetCounts();
  RyujiEv3Engine::GetTailMotor()->setCounts(83, 20, true);
  //*/
  EV3_LOG_DEBUG("CompleteGarage::moveBlueLine start !\n");
  m_gLineTrace->configTraceColor(m_param->area1Config.traceColor);
  m_gLineTrace->configPID(m_param->area1Config.pid);
  // m_gLineTrace->Drive(m_param->area1Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation() == 1) {
  }

  return true;
}

bool CompleteGarage::moveBlackLine() {
  EV3_LOG_DEBUG("CompleteGarage::moveBlackLine start !\n");
  m_gLineTrace->configTraceColor(m_param->area2Config.traceColor);
  m_gLineTrace->configPID(m_param->area2Config.pid);
  m_gLineTrace->Drive(m_param->area2Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation() == 2) {
  }
  m_gLineTrace->stop();
  return true;
}

bool CompleteGarage::moveGarage() {
  EV3_LOG_DEBUG("CompleteGarage::moveGarage start !\n");
  m_gLineTrace->configTraceColor(m_param->area3Config.traceColor);
  m_gLineTrace->configPID(m_param->area3Config.pid);
  m_gLineTrace->Drive(m_param->area3Config.speed);
  while (m_recognizeCurrentRocation->getCurrentRocation() == 3) {
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