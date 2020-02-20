#include "CalibrationScene2019Logic.h"

CalibrationScene2019Logic::CalibrationScene2019Logic(
    Calibration2019Param* param) {
  EV3_LOG_INFO("CalibrationScene2019Logic Constractar  !\n");
  m_param = param;
}

bool CalibrationScene2019Logic::init() {
  EV3_LOG_DEBUG("CalibrationScene2019Logic::init() start\n");
  //尻尾のあそびをなくす
  if (!RyujiEv3Engine::GetTailMotor()->setCounts(-3, 100, false)) {
    EV3_LOG_ERROR("GetTailMotor()->resetCounts()\n");
    return false;
  }
  tslp_tsk(1000);
  RyujiEv3Engine::GetTailMotor()->resetCounts();
  EV3_LOG_DEBUG("CalibrationScene2019Logic::init() end\n");
  return true;
}

bool CalibrationScene2019Logic::run() {
  EV3_LOG_DEBUG("CalibrationScene2019Logic::run() start\n");
  // TODO calibration
  // vector要素分、ループする
  for (unsigned int i = 0; i < m_tailDegree.size(); i++) {
    //尻尾動かす
    if (!RyujiEv3Engine::GetTailMotor()->setCounts(m_tailDegree[i],
                                                   m_param->tailSpeed)) {
      EV3_LOG_ERROR("GetTailMotor()->resetCounts()\n");
      return false;
    }

    //値取得
    RyujiEv3Engine::GetLCD()->drawString(0, 0, "GetClr:BLACK:%d",
                                         m_tailDegree[i]);
    do {
      RyujiEv3Engine::GetTouchSensor()->update();
    } while (RyujiEv3Engine::GetTouchSensor()->clicked() == false);

    RGB rgb          = Drive::ColorCalibrate::RGBAverage1Sec();
    countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
    RyujiEv3Engine::GetSpeaker()->setVolume(50);
    RyujiEv3Engine::GetSpeaker()->playTone(500, 10);

    //白
    RyujiEv3Engine::GetLCD()->drawString(0, 0, "GetClr:WHITE:%d",
                                         m_tailDegree[i]);

    do {
      RyujiEv3Engine::GetTouchSensor()->update();
    } while (!RyujiEv3Engine::GetTouchSensor()->clicked());
    rgb              = Drive::ColorCalibrate::RGBAverage1Sec();
    countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
    RyujiEv3Engine::GetSpeaker()->playTone(500, 10);

    //青
    RyujiEv3Engine::GetLCD()->drawString(
        0, 0, "GetClr:BLUE:%d",
        m_tailDegree[i]);  // Takeuchi(綴り訂正)
    do {
      RyujiEv3Engine::GetTouchSensor()->update();
    } while (!RyujiEv3Engine::GetTouchSensor()->clicked());
    countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
    RyujiEv3Engine::GetSpeaker()->playTone(1000, 15);
    EV3_LOG(
        "degree = %d\n"
        "Add Trace Color black = %f\n"
        "Add Trace Color white = %f\n",
        "Add Trace Color blue = R%dG%dB%d\n", m_tailDegree[i], countColor.black,
        countColor.white, countColor.blue.r, countColor.blue.g,
        countColor.blue.b);  // Takeuchi
    Drive::ColorCalibrate::AddTraceColor(m_tailDegree[i], countColor);

    if (!RyujiEv3Engine::GetTailMotor()->setCounts(m_tailDegree[i] * (-1),
                                                   m_param->tailSpeed, true)) {
      EV3_LOG_ERROR("GetTailMotor()->resetCounts()\n");
      return false;
    }
  }
  EV3_LOG_DEBUG("CalibrationScene2019Logic::run() end\n");
  return true;
}

CalibrationScene2019Logic::~CalibrationScene2019Logic() {
  EV3_LOG_INFO("CalibrationScene2019Logic Detractar !\n");
}