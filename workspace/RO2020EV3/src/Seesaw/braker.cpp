#include "braker.h"

bool braker::run(void) {
  EV3_LOG("braker__start\n");

  if (!Drive::Stop()) {
    return false;
  }
  if (!RyujiEv3Engine::GetRightMotor()->stop(true)) {
    return false;
  }
  if (!RyujiEv3Engine::GetLeftMotor()->stop(true)) {
    return false;
  }

  m_cnt = 0;
  while (m_cnt < m_delayCnt) {
    if (m_stableOffset > RyujiEv3Engine::GetGyroSensor()->getRate() &&
        RyujiEv3Engine::GetGyroSensor()->getRate() > m_stableOffset * (-1)) {
      m_cnt++;
    }
    // EV3_LOG("angVelValue=%d",RyujiEv3Engine::GetGyroSensor()->getRate());
  }

  EV3_LOG("braker__finish\n");

  return true;
}
