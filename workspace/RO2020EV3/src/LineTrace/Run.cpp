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

	// ライントレースモードにする
	Drive::SetDriveMode(DriveMode::LineTrace);

	//StartDash
	Steering::SetMode(SteeringMode::Balance);		//倒立モード
	dash.tailOperation();			//尻尾上げ

	//走行
	Drive::Drive(100);

	do {
		//走行状態取得
		m_runState = control.drivePosition();

		//走行状態修正
//		control.errorCorrection();

		//走行状態でPIDを切り替える
		trace.lineTraceDrive(m_runState);

	} while (m_runState != Goal);

	while (1) {
		//青検知で走行変化
		m_blueDetection = color.getBlueColor();
			if (m_blueDetection == true) { break; }
	}

	//30%走行
	Drive::Drive(m_lowSpeed);

	while (1) {
		//黒検知で終了
		m_blackDetection = color.getBlackColor();
			if (m_blackDetection == true) { break; }
	}
	/* 難所引き渡し */
}
