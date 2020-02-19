#include "RecognizeCurrentRocation.h"
#include <Logger.h>
RecognizeCurrentRocation::RecognizeCurrentRocation(Garage2019Param* param) {
  m_param = param;
  EV3_LOG_DEBUG("RecognizeCurrentRocation start\n");
  m_detectLineColor = new DetectLineColor;
  m_detectMireage   = new DetectMireage;
}

int RecognizeCurrentRocation::getCurrentRocation() {
  bool detectColorResult;
  float detectDistanceResult;
  //エリア１
  m_detectLineColor->configDetectColor(m_param->area1CurrentColor);
  detectColorResult = m_detectLineColor->detect();
  m_detectMireage->configDetectDistance(m_param->area1EndTrriger.distance);
  detectDistanceResult = m_detectMireage->detect();
  if (detectColorResult == true && detectDistanceResult == false) {
    m_currentArea = 1;
  }

  m_detectLineColor->configDetectColor(m_param->area2CurrentColor);
  detectColorResult = m_detectLineColor->detect();
  m_detectMireage->configDetectDistance(m_param->area1EndTrriger.distance);
  detectDistanceResult = m_detectMireage->detect();
  if (detectColorResult == true && detectDistanceResult == true) {
    m_currentArea = 2;
  }

  m_detectLineColor->configDetectColor(m_param->area3CurrentColor);
  detectColorResult = m_detectLineColor->detect();
  m_detectMireage->configDetectDistance(m_param->area2EndTrriger.distance);
  detectDistanceResult = m_detectMireage->detect();
  if (detectColorResult == true && detectDistanceResult == true) {
    m_currentArea = 3;
  }
  EV3_LOG_DEBUG("CurrentArea=%d\n", m_currentArea);
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