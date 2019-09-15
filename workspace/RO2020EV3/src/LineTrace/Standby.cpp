#include "Standby.h"
#include <Config.h>
#include <Drive.h>
#include <Logger.h>  //Takeuchi
#include "Run.h"
//追�?変更そ�?�他ざっくり by Takeuchi
//ログを吐くよ�?に追�?
//キャリブレーション時、毎回尻尾位置をリセ�?トするよ�?に変更

Standby::Standby() {
  m_tailDegrees.push_back(NomalDeg);

  // L,R,各コースで必要な角度をキャリブレーションする
  m_tailDegrees.push_back(LookUp_1Deg);

  switch (LINETRACE_NEXT_SCENE) {
    case SceneID::Lookup:
      m_tailDegrees.push_back(LookUp_2Deg);
      Drive::LineTrace::SetSide(Side::Right);
      break;
    case SceneID::Seesaw:
      Drive::LineTrace::SetSide(Side::Left);
    default:
      EV3_LOG_ERROR("okapeople");
      break;
  }
}

Standby::~Standby() {}

void Standby::traceMain() {
  EV3_LOG("SetUp Start\n");  // Takeuchi
  setup();
  EV3_LOG("SetUp End\n");  // Takeuchi

  do {
    while (!bluetoothDetection() && !buttonDetection())
      ;
  } while (!runStart());
}

void Standby::setup() {
  auto* tail = RyujiEv3Engine::GetTailMotor();

  //尻尾角度のリセ�?�?
  tail->setCounts(-7, 50, false);  //遊�?�をなくす処�?
  dly_tsk(1000);
  tail->resetCounts();  //尻尾を上にあげきった状態で実�?

  int32 prevCount = 0;

  // キャリブレーションする�?要�?�ある角度をすべて実�?
  for (const auto& itr : m_tailDegrees) {
    tail->setCounts(itr - prevCount, TAIL_SPEED, true);

    Calibration(itr);

    prevCount = itr;
  }

  // スタート�?機状態にしっぽを設�?
  tail->setCounts(STANDBY_COUNT - prevCount, TAIL_SPEED, true);
}

void Standby::Calibration(int32 degree) {
  auto* touch   = RyujiEv3Engine::GetTouchSensor();
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  auto* lcd     = RyujiEv3Engine::GetLCD();

  TraceColor countColor;

  //�?
  lcd->drawString(0, 0, "GetColor : Black : %d", degree);  // Takeuchi(綴り訂正)

  do {
    touch->update();
  } while (!touch->clicked());

  RGB rgb          = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  RyujiEv3Engine::GetSpeaker()->setVolume(255);
  speaker->playTone(500, 10);

  //白
  lcd->drawString(0, 0, "GetColor : White : %d", degree);

  do {
    touch->update();
  } while (!touch->clicked());
  rgb              = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(500, 10);

  //�?
  lcd->drawString(0, 0, "GetColor : Blue : %d", degree);  // Takeuchi(綴り訂正)
  do {
    touch->update();
  } while (!touch->clicked());
  countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
  speaker->playTone(1000, 15);

  EV3_LOG(
      "degree = %d\nAdd Trace Color black = %f\nAdd Trace Color blue = "
      "R%dG%dB%d\nAdd Trace Color white = %f\n",
      degree, countColor.black, countColor.blue.r, countColor.blue.g,
      countColor.blue.b, countColor.white);  // Takeuchi
  Drive::ColorCalibrate::AddTraceColor(degree, countColor);
}

bool Standby::bluetoothDetection() {
  auto* bluetooth = RyujiEv3Engine::GetBluetooth();

  if (!bluetooth->isConnected()) {
    return false;
  }

  // スタート識別信号
  constexpr uint8 START_SIGNAL = '1';

  return bluetooth->read() == START_SIGNAL;
}

bool Standby::buttonDetection() {
  auto* touch = RyujiEv3Engine::GetTouchSensor();

  touch->update();

  return touch->clicked();
}

bool Standby::runStart() {
  Run start;

  if (!start.driveStart()) {
    RyujiEv3Engine::GetTailMotor()->setCounts(-5, 50,
                                              false);  //遊�?�をなくす処�?
    dly_tsk(500);
    RyujiEv3Engine::GetTailMotor()
        ->resetCounts();  //尻尾を上にあげきった状態で実�?
    RyujiEv3Engine::GetTailMotor()->setCounts(STANDBY_COUNT, TAIL_SPEED, true);
    return false;
  }

  return true;
}
