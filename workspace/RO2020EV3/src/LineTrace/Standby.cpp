#include "Standby.h"
#include <Drive.h>
#include "Run.h"
#include <Logger.h>                               //Takeuchi

//�ǉ��ύX���̑��������� by Takeuchi
//���O��f���悤�ɒǉ�
//�L�����u���[�V�������A����K���ʒu�����Z�b�g����悤�ɕύX

Standby::Standby() {}

Standby::~Standby() {}

void Standby::traceMain() {
  //auto* Bluetooth = RyujiEv3Engine::GetBluetooth();
  EV3_LOG("SetUp Start\n");                       //Takeuchi
  setup();    // hs キャリブレーション
  EV3_LOG("SetUp End\n");                         //Takeuchi
#if defined LINETRACE_BLUETOOTH_START
  while (!bluetoothDetection())
    ;
#else
  EV3_LOG("ButtonDetection Start\n");             //Takeuchi
  while (!buttonDetection())
    ;
  EV3_LOG("ButtonDetection End\n");               //Takeuchi
#endif
  EV3_LOG("Run Start\n");                         //Takeuchi
  //runStart();    //hs ライントレース開始
  EV3_LOG("End\n");                               //Takeuchi
}

void Standby::setup() {
  auto* tail = RyujiEv3Engine::GetTailMotor();
  //constexpr int32 TAIL_SPEED = 70;	//�����ۃ��[�^��]���x

  int cnt = 0;                                      //Takeuchi
  int32 degReset = 0;                               //Takeuchi(�K���p�x����ԏ�ɖ߂����߂̊p�x)

  //�K���p�x�̃��Z�b�g
  tail->resetCounts();  //�K������ɂ�����������ԂŎ��s

  for (const auto& itr : m_tailDegrees) {
    //tail->setCounts(itr, TAIL_SPEED, true);         //Old

    //�K���p�x�̃��Z�b�g                                Takeuchi Old
    /*
    if (cnt != 0) {                                   //Takeuchi
      degReset = 0;                                   //Takeuchi
      degReset -= m_tailDegrees[cnt];                 //Takeuchi
      tail->setCounts(itr, degReset, true);           //Takeuchi
    }*/

    tail->setCounts(itr, m_tailDegrees[cnt], true);   //Takeuchi(m_tailDegrees�Ɋi�[����Ă���e�p�x�������Ăяo��)
    Calibration(itr);

    //Takeuchi(�K�������������������ɖ߂�)
    degReset = 0;                                   //Takeuchi
    degReset -= m_tailDegrees[cnt];                 //Takeuchi
    tail->setCounts(itr, degReset, true);           //Takeuchi

    ++cnt;                                          //Takeuchi
  }

  //tail->setCounts(90, 50, true);                   //Takeuchi(�K�����X�^�[�g�O�̑ҋ@�|�W�V������(�p�x90���͓K��))
}

void Standby::Calibration(int32 degree) {
  auto* touch   = RyujiEv3Engine::GetTouchSensor();
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  auto* lcd     = RyujiEv3Engine::GetLCD();

  TraceColor countColor;

  //��
  lcd->drawString(0, 0, "GetColor : Black : %d", degree);//Takeuchi(�Ԃ����)

  do {
    touch->update();
  } while (!touch->clicked());

  RGB rgb          = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //��
  lcd->drawString(0, 0, "GetColor : White : %d", degree);

  do {
    touch->update();
  } while (!touch->clicked());
  rgb              = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //��
  lcd->drawString(0, 0, "GetColor : Blue : %d", degree);//Takeuchi(�Ԃ����)
  do {
    touch->update();
  } while (!touch->clicked());
  rgb             = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.blue =(static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);


  EV3_LOG("degree = %d\nAdd Trace Color black = %f\nAdd Trace Color blue = %f\nAdd Trace Color white = %f\n", degree, countColor.black, countColor.blue, countColor.white);//Takeuchi
  Drive::ColorCalibrate::AddTraceColor(degree, countColor);
}

bool Standby::bluetoothDetection() {
  auto* bluetooth = RyujiEv3Engine::GetBluetooth();

  if (!bluetooth->isConnected()) {
    return false;
  }

  // �X�^�[�g���ʐM��
  constexpr uint8 START_SIGNAL = '1';

  // �X�^�[�g�M����M�܂őҋ@
  while (bluetooth->read() != START_SIGNAL)
    ;

  return true;
}

bool Standby::buttonDetection() {
  auto* touch = RyujiEv3Engine::GetTouchSensor();
  auto* lcd = RyujiEv3Engine::GetLCD();//Takeuchi
  lcd->drawString(0, 0, "Plese Push Botton");//Takeuchi
  // Button�A�����ꂽ��true�����^�[��
  do {
    touch->update();
  } while (!touch->clicked());

  return true;
}

void Standby::runStart() {
  Run start;
  start.driveStart();
}
