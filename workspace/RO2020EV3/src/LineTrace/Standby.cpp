#include "Standby.h"
#include <Drive.h>
#include "Run.h"

Standby::Standby() {}

Standby::~Standby() {}

void Standby::traceMain() {
  auto* Bluetooth = RyujiEv3Engine::GetBluetooth();

  setup();

#if defined LINETRACE_BLUETOOTH_START
  while (!bluetoothDetection())
    ;
#else
  while (!buttonDetection())
    ;
#endif

  runStart();
}

void Standby::setup() {
  auto* tail = RyujiEv3Engine::GetTailMotor();
  constexpr int32 TAIL_SPEED = 70;	//しっぽモータ回転速度

  //尻尾角度のリセット
  tail->resetCounts();  //尻尾を上にあげきった状態で実行

  for (const auto& itr : m_tailDegrees) {
    tail->setCounts(itr, TAIL_SPEED, true);
    Calibration(itr);
  }
}

void Standby::Calibration(int32 degree) {
  auto* touch   = RyujiEv3Engine::GetTouchSensor();
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  auto* lcd     = RyujiEv3Engine::GetLCD();

  TraceColor countColor;

  //黒
  lcd->drawString(0, 0, "GetColor : Bkack : %d", degree);

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
  lcd->drawString(0, 0, "GetColor : Bkack : %d", degree);
  do {
    touch->update();
  } while (!touch->clicked());
  countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
  speaker->playTone(600, 1);

  Drive::ColorCalibrate::AddTraceColor(degree, countColor);
}

bool Standby::bluetoothDetection() {
  auto* bluetooth = RyujiEv3Engine::GetBluetooth();

  if (!bluetooth->isConnected()) {
    return false;
  }

  // スタート識別信号
  constexpr uint8 START_SIGNAL = '1';

  // スタート信号受信まで待機
  while (bluetooth->read() != START_SIGNAL)
    ;

  return true;
}

bool Standby::buttonDetection() {
  auto* touch = RyujiEv3Engine::GetTouchSensor();

  // Button、押されたらtrueをリターン
  do {
    touch->update();
  } while (!touch->clicked());

  return true;
}

void Standby::runStart() {
  Run start;
  start.driveStart();
}
