#include "Run.h"
#include <Drive.h>
#include <Logger.h>  //Takeuchi
#include <Steering.h>
#include "ColorDetection.h"
#include "LineTrace.h"
#include "MapStateControl.h"
#include "StartDash.h"
#include "ev3api.h"  //Takeuchi
Run::Run() {}

Run::~Run() {}

bool Run::driveStart() {
  StartDash dash;
  MapStateControl control;
  LineTrace trace;
  ColorDetection color;

  // SetTraceColor�ǉ�//Takeuchi
  TraceColor traceColor;  // Takeuchi
  traceColor = Drive::ColorCalibrate::GetTraceColor(
      90);  // Takeuchi(Nomal Degree(90��)�œo�^���ꂽ�g���[�X�J���[���Ăяo��)
  Drive::LineTrace::SetTraceColor(traceColor);  // Takeuchi

  //�g���[�X�J���[���Z�b�g����Ă邩�̊m�F//Takeuchi
  //�Z�b�g�����͂��̃g���[�X�J���[//Takeuchi

  //���ۂɃZ�b�g����Ă���Z�b�g�J���[//Takeuchi
  traceColor = Drive::LineTrace::
      GetTraceColor();  // Takeuchi(���݃Z�b�g����Ă���g���[�X�J���[���擾)//Takeuchi

  // StartDash
  dash.startRun();

  auto* touch = RyujiEv3Engine::GetTouchSensor();

  do {
    touch->update();

    // �{�^���N���b�N�Ń��X�^�[�g
    if (touch->clicked()) {
      Steering::SetMode(SteeringMode::Nomal);
      Drive::SetDriveMode(DriveMode::Nomal);
      Drive::Stop();
      Steering::ResetDistance();
      return false;
    }

    //���s��Ԏ擾
    m_runState = control.drivePosition();

    if (m_runState == -1) {
      break;
    }
    //���s��Ԃ�PID��؂�ւ���
    trace.lineTraceDrive(m_runState);

  } while (true);
  EV3_LOG("GOOOOOOL");
  
  Drive::LineTrace::SetPID({0.4f, 0.0f, 0.2f});
  Drive::Drive(30);
  //  RyujiEv3Engine::GetSpeaker()->playTone(1000, 1000);
  Drive::LineTrace::SetLineMode(BlueLineMode::Blue);

  // �����m
  while (!color.getBlueColor()) {
    dly_tsk(100);
  };
  //  RyujiEv3Engine::GetSpeaker()->playTone(700, 1000);

  // 30%���s
  // Drive::Drive(m_lowSpeed);
  EV3_LOG("Im blue now");  // Takeuchi
  // ���C�������F�ɂȂ������ֈ����n��
  while (!color.getBlackColor()) {
    dly_tsk(100);
  };
  EV3_LOG("LineTrace End");
  /* ������n�� */
  return true;
}
