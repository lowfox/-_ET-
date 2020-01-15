#include "angleDetector.h"

bool angleDetector::setTargetValue(int16 target) {
  EV3_LOG("angleDetector__setTargerValue__start\n");
  if (target > 180 || target < -180) {
    return false;
  }
  m_targetValue = target;
  EV3_LOG("angleDetector__setTargetValue__finish\n");
  return true;
}

bool angleDetector::detect() {
  if (m_targetValue > 180) {
    return false;
  }
  int16 value;
// 4�x�̌덷��+-�P�����e
#ifdef TESTMODE
  value = testValue;
#else
  value = RyujiEv3Engine::GetGyroSensor()->getAngle();
#endif
  if ((value - m_targetValue) < 2 && (value - m_targetValue) > -2) {
    EV3_LOG("angleDetector__detect!!!!\n");
    return true;
  }
  // EV3_LOG("targetValue=%d, angleValue=%d",m_targetValue,value);
  return false;
}

#ifdef TESTMODE
void angleDetector::setTestValue(int16 inputValue) { testValue = inputValue; }
#endif