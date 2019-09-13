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

bool Run::driveStart() {
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
  //���ۂɃZ�b�g����Ă���Z�b�g�J���[//Takeuchi
  traceColor = Drive::LineTrace::GetTraceColor();//Takeuchi(���݃Z�b�g����Ă���g���[�X�J���[���擾)//Takeuchi
  EV3_LOG("Now Trace Color black = %f\nNow Trace Color blue = %f\nNow Trace Color white = %f\n", traceColor.black, traceColor.blue, traceColor.white);//Takeuchi


  // StartDash
  Steering::SetMode(SteeringMode::Balance);  //�|�����[�h
  dash.tailOperation();                      //�K���グ

  Drive::Drive(50);

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

    //���s��Ԃ�PID��؂�ւ���
    trace.lineTraceDrive(m_runState);

  } while (m_runState != Goal);


  float milage = 0.0f;          //�݌v����
  //�݌v�����擾
  milage = DistanceMeasure::getDistance();
  //Takeuchi �S�[�����_�ł̗݌v���������O�ŕ\��
  EV3_LOG("Goal now milage  = %f\n", milage);//Takeuchi


  // �����m
  while (!color.getBlueColor())
    ;
  // 30%���s
  Drive::Drive(m_lowSpeed);
  EV3_LOG("Im blue now");//Takeuchi
  // ���C�������F�ɂȂ������ֈ����n��
  while (!color.getBlackColor())
    ;
  /* ������n�� */
  return true;
}
