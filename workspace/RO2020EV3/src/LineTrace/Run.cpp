#include "Run.h"
#include "StartDash.h"
#include "MapStateControl.h"
#include "LineTrace.h"
#include "ColorDetection.h"
#include <Drive.h>
#include <Steering.h>


Run::Run() {}

Run::~Run() {}


void Run::driveStart() {
	StartDash dash;
	MapStateControl control;
	LineTrace trace;
	ColorDetection color;

	// ���C���g���[�X���[�h�ɂ���
	Drive::SetDriveMode(DriveMode::LineTrace);

	//StartDash
	Steering::SetMode(SteeringMode::Balance);		//�|�����[�h
	dash.tailOperation();			//�K���グ

	//���s
	Drive::Drive(100);

	do {
		//���s��Ԏ擾
		m_runState = control.drivePosition();

		//���s��ԏC��
//		control.errorCorrection();

		//���s��Ԃ�PID��؂�ւ���
		trace.lineTraceDrive(m_runState);

	} while (m_runState != Goal);

	while (1) {
		//���m�ő��s�ω�
		m_blueDetection = color.getBlueColor();
			if (m_blueDetection == true) { break; }
	}

	//30%���s
	Drive::Drive(m_lowSpeed);

	while (1) {
		//�����m�ŏI��
		m_blackDetection = color.getBlackColor();
			if (m_blackDetection == true) { break; }
	}
	/* ������n�� */
}
