#include "RecognizeCurrentRocation.h"
#include <Logger.h>
RecognizeCurrentRocation::RecognizeCurrentRocation(Garage2019Param* param) {
  m_param = param;
  EV3_LOG_DEBUG("RecognizeCurrentRocation start\n");
  m_detectLineColor = new DetectLineColor;
  m_detectMireage   = new DetectMireage;
}

int RecognizeCurrentRocation::getCurrentRocation() {
  bool detectResult;
  m_detectLineColor->configDetectColor(ReadColor::BLUE);
  detectResult = m_detectLineColor->detect();

  if (detectResult == true) {
    m_currentArea = 2;
  }
  return m_currentArea;
}

bool RecognizeCurrentRocation::endDelete() {
  delete m_detectLineColor;
  delete m_detectMireage;
  return true;
}

RecognizeCurrentRocation::~RecognizeCurrentRocation() {
  EV3_LOG_DEBUG("RecognizeCurrentRocation End\n");
  endDelete();
}