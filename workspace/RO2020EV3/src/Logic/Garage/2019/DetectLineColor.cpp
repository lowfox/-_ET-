#include "DetectLineColor.h"

void DetectLineColor::configDetectColor(ReadColor color) {
  m_detectColor = color;
}

bool DetectLineColor::detect() {
  for (m_detectCnt = 0; m_detectCnt < 10; m_detectCnt++) {
    m_currentColor[m_detectCnt] = RyujiEv3Engine::GetColorSensor()->getColor();

    //ここswitch
    if (m_currentColor[m_detectCnt] == ReadColor::BLACK) {
      EV3_LOG_DEBUG("ReadColor : %d : BLACK\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::BLUE) {
      EV3_LOG_DEBUG("ReadColor : %d : BLUE\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::WHITE) {
      EV3_LOG_DEBUG("ReadColor : %d : WHITE\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::YELLOW) {
      EV3_LOG_DEBUG("ReadColor : %d : YELLOW\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::RED) {
      EV3_LOG_DEBUG("ReadColor : %d : RED\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::GREEN) {
      EV3_LOG_DEBUG("ReadColor : %d : GREEN\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::BROWN) {
      EV3_LOG_DEBUG("ReadColor : %d : BROWN\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
    if (m_currentColor[m_detectCnt] == ReadColor::NONE) {
      EV3_LOG_DEBUG("ReadColor : %d : NONE\n",
                    static_cast<int>(m_currentColor[m_detectCnt]));
    }
  }
  // 10個全部揃ってたら検知
  for (m_detectCnt = 1; m_detectCnt < 10; m_detectCnt++) {
    if (m_currentColor[0] == m_currentColor[m_detectCnt]) {
      m_trueCnt++;
    }
  }
  if (m_trueCnt != 10) {
    return false;
  }
  return true;
}