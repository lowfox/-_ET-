#pragma once
#include <RyujiEv3.h>
#include <vector>

constexpr int32 NomalDeg    = 90;
constexpr int32 LookUp_1Deg = 80;
constexpr int32 LookUp_2Deg = 55;

//#define LINETRACE_BLUETOOTH_START

//ライントレーススタンバイ
class Standby {
 private:
  std::vector<int32> m_tailDegrees;

  const int32 TAIL_SPEED = 50;  //しっぽモータ回転速度

  const int32 STANDBY_COUNT = 90;  //待機時のしっぽ角度

 public:
  Standby();
  ~Standby();

  void traceMain();

  void setup();

 private:
  void Calibration(int32 degree);

  bool buttonDetection();

  bool bluetoothDetection();

  bool runStart();
};
