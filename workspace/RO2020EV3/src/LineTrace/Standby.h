#pragma once
#include <RyujiEv3.h>
#include <vector>

constexpr int32 NomalDeg    = 90;
constexpr int32 LookUp_1Deg = 83;
constexpr int32 LookUp_2Deg = 62;

//#define LINETRACE_BLUETOOTH_START

//���C���g���[�X�X�^���o�C
class Standby {
 private:
  std::vector<int32> m_tailDegrees;

  const int32 TAIL_SPEED = 50;  //�����ۃ��[�^��]���x

  const int32 STANDBY_COUNT = 90;  //�ҋ@���̂����ۊp�x

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
