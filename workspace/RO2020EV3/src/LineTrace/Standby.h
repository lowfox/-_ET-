#pragma once
#include <RyujiEv3.h>
#include <vector>

constexpr int32 NomalDeg    = 90;
constexpr int32 LookUp_1Deg = 83;
constexpr int32 LookUp_2Deg = 62;

//#define LINETRACE_BLUETOOTH_START

//?¿½?¿½?¿½C?¿½?¿½?¿½g?¿½?¿½?¿½[?¿½X?¿½X?¿½^?¿½?¿½?¿½o?¿½C
class Standby {
 private:
  std::vector<int32> m_tailDegrees;

  const int32 TAIL_SPEED = 50;  //?¿½?¿½?¿½?¿½?¿½Û??¿½?¿½[?¿½^?¿½?¿½]?¿½?¿½?¿½x

  const int32 STANDBY_COUNT = 91;  //?¿½Ò‹@?¿½?¿½?¿½Ì‚ï¿½?¿½?¿½?¿½ÛŠp?¿½x

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
