#include "Standby.h"
#include <Config.h>
#include <Drive.h>
#include <Logger.h>  //Takeuchi
#include "Run.h"

//追加変更その他ざっくり by Takeuchi
//ログを吐くように追加
//キャリブレーション時、毎回尻尾位置をリセットするように変更

Standby::Standby() {
  m_tailDegrees.push_back(NomalDeg);

  // L,R,各コースで必要な角度をキャリブレーションする
  switch (LINETRACE_NEXT_SCENE) {
    case SceneID::Lookup:
      m_tailDegrees.push_back(LookUp_1Deg);
      m_tailDegrees.push_back(LookUp_2Deg);
      break;
    case SceneID::Seesaw:

      break;
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
	  while (!bluetoothDetection() && !buttonDetection());
  } while (!runStart());
}

void Standby::setup() {
  auto* tail                    = RyujiEv3Engine::GetTailMotor();

  //尻尾角度のリセット
  tail->resetCounts();  //尻尾を上にあげきった状態で実行

  int32 prevCount = 0;

  // キャリブレーションする必要のある角度をすべて実行
  for (const auto& itr : m_tailDegrees) {
    tail->setCounts(itr - prevCount, TAIL_SPEED, true);

    Calibration(itr);

    prevCount = itr;
  }

  // スタート待機状態にしっぽを設定
  tail->setCounts(STANDBY_COUNT - prevCount, TAIL_SPEED, true);
}

void Standby::Calibration(int32 degree) {
  auto* touch   = RyujiEv3Engine::GetTouchSensor();
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  auto* lcd     = RyujiEv3Engine::GetLCD();

  TraceColor countColor;

  //黒
  lcd->drawString(0, 0, "GetColor : Black : %d", degree);  // Takeuchi(綴り訂正)

  do {
    touch->update();
  } while (!touch->clicked());

  RGB rgb          = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //白
  lcd->drawString(0, 0, "GetColor : White : %d", degree);

  do {
    touch->update();
  } while (!touch->clicked());
  rgb              = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //青
  lcd->drawString(0, 0, "GetColor : Blue : %d", degree);  // Takeuchi(綴り訂正)
  do {
    touch->update();
  } while (!touch->clicked());
  countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
  speaker->playTone(600, 1);

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
	  RyujiEv3Engine::GetTailMotor()->setCounts(STANDBY_COUNT, TAIL_SPEED, true);
	  return false;
  }

  return true;
}
