#include "DetectMireage.h"

void DetectMireage::configDetectDistance(float mireage) {
  m_detectMireage = mireage;
}

bool DetectMireage::detect() {
  m_currentMireage = Steering::GetDistance();
  if (m_currentMireage != m_detectMireage) {
    return false;
  }
  return true;
}