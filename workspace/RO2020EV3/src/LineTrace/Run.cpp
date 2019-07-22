#include "Run.h"
#include <Drive.h>
#include <Steering.h>
#include "ColorDetection.h"
#include "LineTrace.h"
#include "MapStateControl.h"
#include "StartDash.h"

Run::Run() {}

Run::~Run() {}

void Run::driveStart() {
  StartDash dash;
  MapStateControl control;
  LineTrace trace;
  ColorDetection color;

  // ���C���g���[�X���[�h�ɂ���
  Drive::SetDriveMode(DriveMode::LineTrace);

  // StartDash
  Steering::SetMode(SteeringMode::Balance);  //�|�����[�h
  dash.tailOperation();                      //�K���グ

  //���s
  Drive::Drive(100);

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
  while (color.getBlackColor())
    ;
  /* ������n�� */
}
