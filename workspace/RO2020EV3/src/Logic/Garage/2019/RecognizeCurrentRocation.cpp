#include "RecognizeCurrentRocation.h"
RecognizeCurrentRocation::RecognizeCurrentRocation(Garage2019Param* param) {
  m_param = param;
  EV3_LOG_DEBUG("RecognizeCurrentRocation start\n");
  m_detectLineColor = new DetectLineColor;
  m_detectMireage   = new DetectMireage;
}

bool RecognizeCurrentRocation::getCurrentRocation(int areaNo) {
  bool detectColorResult;
  float detectDistanceResult;
  //エリア１
  if (areaNo == 1) {
    m_detectLineColor->configDetectColor(
        m_param->area1EndTrriger.detectLineColor);
    detectColorResult = m_detectLineColor->detect();

    if (detectColorResult == true) {
      RyujiEv3Engine::GetSpeaker()->setVolume(30);
      RyujiEv3Engine::GetSpeaker()->playTone(40, 30);
      EV3_LOG_DEBUG("-------------------Area 1 CLEAR!---------------------\n");
      return true;
    }
  }

  if (areaNo == 2) {
    m_detectLineColor->configDetectColor(
        m_param->area2EndTrriger.detectLineColor);
    detectColorResult = m_detectLineColor->detect();
    if (detectColorResult == true) {
      RyujiEv3Engine::GetSpeaker()->setVolume(30);
      RyujiEv3Engine::GetSpeaker()->playTone(60, 30);
      EV3_LOG_DEBUG("-------------------Area 2 CLEAR!---------------------\n");
      return true;
    }
  }

  if (areaNo == 3) {
    m_detectMireage->configDetectDistance(m_param->area3EndTrriger.distance);
    detectDistanceResult = m_detectMireage->detect();
    if (detectDistanceResult == true) {
      RyujiEv3Engine::GetSpeaker()->setVolume(30);
      RyujiEv3Engine::GetSpeaker()->playTone(90, 30);
      EV3_LOG_DEBUG("-------------------Area 3 CLEAR!---------------------\n");
      return true;
    }
  }
  return false;
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