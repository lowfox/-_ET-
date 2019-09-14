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
  traceColor = Drive::ColorCalibrate::GetTraceColor(90);  // Takeuchi(Nomal Degree(90��)�œo�^���ꂽ�g���[�X�J���[���Ăяo��)
  Drive::LineTrace::SetTraceColor(traceColor);  // Takeuchi

  //�g���[�X�J���[���Z�b�g����Ă邩�̊m�F//Takeuchi
  //�Z�b�g�����͂��̃g���[�X�J���[//Takeuchi

  //���ۂɃZ�b�g����Ă���Z�b�g�J���[//Takeuchi
  traceColor = Drive::LineTrace::
      GetTraceColor();  // Takeuchi(���݃Z�b�g����Ă���g���[�X�J���[���擾)//Takeuchi

  // StartDash
  dash.startRun();

  auto* touch = RyujiEv3Engine::GetTouchSensor();
  float m_firstDistance=Steering::GetDistance();
  
  do {
   touch->update();

    // ?{?^???N???b?N????X?^?[?g
    if (touch->clicked()) {
      Steering::SetMode(SteeringMode::Nomal);
      Drive::SetDriveMode(DriveMode::Nomal);
      Drive::Stop();
      Steering::ResetDistance();
      return false;
    }

    //???s???��
   m_runState = control.drivePosition();       //****************************??PID&?X?s?[?h???J??i?R?????g?A?E?g?I?j

    if (m_runState == -1) {
      break;
    }
    //???s????PID????????
    if(m_runState > 0){
      trace.lineTraceDrive(m_runState);            //****************************??PID&?X?s?[?h???I?Z?b?g?i?R?????g?A?E?g?I?j
    }
    EV3_LOG("m_runstate = %d",m_runState);
    //auto now_distance = Steering::GetDistance();
    if(m_runState == 0 ){
    // while(m_runState <= 1){
      Drive::LineTrace::SetPID({0.3f, 0.0f, 0.2f});  //****************************???Z?b?gPID?i?o????????????????J?[?u???????????j
      Drive::Drive(1);                              //****************************???Z?b?g?X?s?[?h(0?`100)
      dly_tsk(25);
      Drive::Drive(5);                              //****************************???Z?b?g?X?s?[?h(0?`100)
      dly_tsk(100);
      Drive::Drive(10);                              //****************************???Z?b?g?X?s?[?h(0?`100)
      dly_tsk(500);
      Drive::Drive(35);                              //****************************???Z?b?g?X?s?[?h(0?`100)
      dly_tsk(1500);
    }

  } while (true);
  float goalDistance=Steering::GetDistance();

  EV3_LOG("GOOOOOOL");
  
  
  //Drive::LineTrace::SetPID({0.4f, 0.0f, 0.2f});
  //Drive::SetDriveMode(DriveMode::Nomal);
  Drive::Drive(40);
  //  RyujiEv3Engine::GetSpeaker()->playTone(1000, 1000);
  //Drive::LineTrace::SetLineMode(BlueLineMode::Blue);

  while(Steering::GetDistance() - goalDistance < 1000.0f){}
  Drive::Drive(10);

  //Drive::Stop();
  // �����m
  /*
  while (!color.getBlueColor()) {
    dly_tsk(100);
  };
  */
  RyujiEv3Engine::GetSpeaker()->playTone(700, 1000);

  // 30%���s
  // Drive::Drive(m_lowSpeed);
 // EV3_LOG("Im blue now");  // Takeuchi
  // ���C�������F�ɂȂ������ֈ����n��
  /*
  while (!color.getBlackColor()) {
    dly_tsk(100);
  };
  */
  EV3_LOG("LineTrace End");
  /* ������n�� */
  return true;
}
