#pragma once
#include <RyujiEv3.h>
#include <vector>

constexpr int32 NomalDeg    = 90;
constexpr int32 LookUp_1Deg = 83;
constexpr int32 LookUp_2Deg = 62;

//#define LINETRACE_BLUETOOTH_START

//?申?申?申C?申?申?申g?申?申?申[?申X?申X?申^?申?申?申o?申C
class Standby {
 private:
  std::vector<int32> m_tailDegrees;

  const int32 TAIL_SPEED = 50;  //?申?申?申?申?申�??申?申[?申^?申?申]?申?申?申x

  const int32 STANDBY_COUNT = 91;  //?申��@?申?申?申��鐃�?申?申?申��p?申x

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
