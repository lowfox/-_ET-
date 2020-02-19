#include "DetectMireage.h"

void DetectMireage::configDetectDistance(float mireage) {
  m_detectMireage = mireage;
}

bool DetectMireage::detect() {
  m_currentMireage = Steering::GetDistance();
  EV3_LOG_DEBUG("nowDistance = %f\n", m_currentMireage);
  if (m_currentMireage < m_detectMireage) {
    return false;
  }
  return true;
}