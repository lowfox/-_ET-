#include "Run.h"
#include <Drive.h>
#include <Steering.h>
#include "ColorDetection.h"
#include "LineTrace.h"
#include "MapStateControl.h"
#include "StartDash.h"
#include <Logger.h>//Takeuchi
#include "ev3api.h"//Takeuchi
Run::Run() {}

Run::~Run() {}

void Run::driveStart() {
  StartDash dash;
  MapStateControl control;
  LineTrace trace;
  ColorDetection color;

  // ���C���g���[�X���[�h�ɂ���
  Drive::SetDriveMode(DriveMode::LineTrace);

  //SetTraceColor�ǉ�//Takeuchi
  TraceColor traceColor;                      //Takeuchi
  traceColor = Drive::ColorCalibrate::GetTraceColor(90);    //Takeuchi(Nomal Degree(90��)�œo�^���ꂽ�g���[�X�J���[���Ăяo��)
  Drive::LineTrace::SetTraceColor(traceColor);//Takeuchi

  //�g���[�X�J���[���Z�b�g����Ă邩�̊m�F//Takeuchi
  //�Z�b�g�����͂��̃g���[�X�J���[//Takeuchi
  EV3_LOG("Set Trace Color black = %f\nSet Trace Color blue = %f\nSet Trace Color white = %f\n", traceColor.black, traceColor.blue, traceColor.white);//Takeuchi
  //���ۂɃZ�b�g����Ă���Z�b�g�J�A���[//Takeuchi
  traceColor = Drive::LineTrace::GetTraceColor();//Takeuchi(���݃Z�b�g����Ă���g���[�X�J���[���擾)//Takeuchi
  EV3_LOG("Now Trace Color black = %f\nNow Trace Color blue = %f\nNow Trace Color white = %f\n", traceColor.black, traceColor.blue, traceColor.white);//Takeuchi


  // StartDash
  Steering::SetMode(SteeringMode::Balance);  //�|�����[�h
  dash.tailOperation();                      //�K���グ

  //���s
  //Drive::Drive(100);                       //old

  //Takeuhi(�ő�100%�܂ŏ��X�ɑ��x���グ�Ă���(�X�^�[�g���̖\����h�����߂̎���))

  Drive::Drive(10);                        //Takeuchi
  Drive::LineTrace::SetPID({ 1.0f, 0.0f, 1.0f });//PID�Z�b�gTakeuchi
  dly_tsk(4000);                          //Takeuchi4000ms�ҋ@

  Drive::Drive(25);                        //Takeuchi
  Drive::LineTrace::SetPID({ 0.5f, 0.0f, 0.3f });//PID�Z�b�gTakeuchi
  dly_tsk(2000);                          //Takeuchi2000ms�ҋ@

  Drive::Drive(50);                        //Takeuchi
  Drive::LineTrace::SetPID({ 0.2f, 0.0f, 0.1f });//PID�Z�b�gTakeuchi
  dly_tsk(2000);                          //Takeuchi2000ms�ҋ@

  Drive::Drive(75);                        //Takeuchi
  Drive::LineTrace::SetPID({ 0.05f, 0.0f, 0.025f });//PID�Z�b�gTakeuchi
  dly_tsk(2000);                          //Takeuchi2000ms�ҋ@

  Drive::Drive(70);                        //Takeuchi

  do {
    //���s��Ԏ擾
    m_runState = control.drivePosition();

    //���s��Ԃ�PID��؂�ւ���
    trace.lineTraceDrive(m_runState);

  } while (m_runState != Goal);

  // �����m
  while (!color.getBlueColor())
    ;
  // 30%���s
  Drive::Drive(m_lowSpeed);

  // ���C�������F�ɂȂ������ֈ����n��
  while (!color.getBlackColor())
    ;

  /* ������n�� */
}
