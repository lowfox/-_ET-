#pragma once
#include <RyujiEv3.h>
#include <vector>

constexpr int32 NomalDeg    = 88;
constexpr int32 LookUp_1Deg = 80;
constexpr int32 LookUp_2Deg = 55;
//constexpr int32 Seesaw_1Deg = 65;
//constexpr int32 Seesaw_2Deg = 70;
//constexpr int32 Seesaw_3Deg = 75;

//#define LINETRACE_BLUETOOTH_START

//���C���g���[�X�X�^���o�C
class Standby {
 private:
  const std::vector<int32> m_tailDegrees = {NomalDeg,    LookUp_1Deg,
                                            LookUp_2Deg,// Seesaw_1Deg,
                                            //
                                            //Seesaw_2Deg, Seesaw_3Deg,
                                            NomalDeg};

 public:
  Standby();
  ~Standby();

  void traceMain();

  void setup();

 private:
  void Calibration(int32 degree);

  bool buttonDetection();

  bool bluetoothDetection();

  void runStart();
};
