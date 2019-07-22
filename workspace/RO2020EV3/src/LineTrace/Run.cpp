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

  // ライントレースモードにする
  Drive::SetDriveMode(DriveMode::LineTrace);

  // StartDash
  Steering::SetMode(SteeringMode::Balance);  //倒立モード
  dash.tailOperation();                      //尻尾上げ

  //走行
  Drive::Drive(100);

  do {
    //走行状態取得
    m_runState = control.drivePosition();

    //走行状態でPIDを切り替える
    trace.lineTraceDrive(m_runState);

  } while (m_runState != Goal);

  // 青線検知
  while (!color.getBlueColor())
    ;
  // 30%走行
  Drive::Drive(m_lowSpeed);

  // ラインが黒色になったら難所へ引き渡し
  while (color.getBlackColor())
    ;
  /* 難所引き渡し */
}
