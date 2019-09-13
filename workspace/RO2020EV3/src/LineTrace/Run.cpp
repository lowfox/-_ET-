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

  // ライントレースモードにする
  Drive::SetDriveMode(DriveMode::LineTrace);

  //SetTraceColor追加//Takeuchi
  TraceColor traceColor;                      //Takeuchi
  traceColor = Drive::ColorCalibrate::GetTraceColor(90);    //Takeuchi(Nomal Degree(90°)で登録されたトレースカラーを呼び出し)
  Drive::LineTrace::SetTraceColor(traceColor);//Takeuchi

  //トレースカラーがセットされてるかの確認//Takeuchi
  //セットしたはずのトレースカラー//Takeuchi
  EV3_LOG("Set Trace Color black = %f\nSet Trace Color blue = %f\nSet Trace Color white = %f\n", traceColor.black, traceColor.blue, traceColor.white);//Takeuchi
  //実際にセットされているセットカラー//Takeuchi
  traceColor = Drive::LineTrace::GetTraceColor();//Takeuchi(現在セットされているトレースカラーを取得)//Takeuchi
  EV3_LOG("Now Trace Color black = %f\nNow Trace Color blue = %f\nNow Trace Color white = %f\n", traceColor.black, traceColor.blue, traceColor.white);//Takeuchi


  // StartDash
  Steering::SetMode(SteeringMode::Balance);  //倒立モード
  dash.tailOperation();                      //尻尾上げ

  Drive::Drive(50);

  auto* touch = RyujiEv3Engine::GetTouchSensor();

  do {
	touch->update();

	// ボタンクリックでリスタート
	if (touch->clicked()) {
		Steering::SetMode(SteeringMode::Nomal);
		Drive::SetDriveMode(DriveMode::Nomal);
		Drive::Stop();
		Steering::ResetDistance();
		return false;
	}

    //走行状態取得
    m_runState = control.drivePosition();

    //走行状態でPIDを切り替える
    trace.lineTraceDrive(m_runState);

  } while (m_runState != Goal);


  float milage = 0.0f;          //累計距離
  //累計距離取得
  milage = DistanceMeasure::getDistance();
  //Takeuchi ゴール時点での累計距離をログで表示
  EV3_LOG("Goal now milage  = %f\n", milage);//Takeuchi


  // 青線検知
  while (!color.getBlueColor())
    ;
  // 30%走行
  Drive::Drive(m_lowSpeed);
  EV3_LOG("Im blue now");//Takeuchi
  // ラインが黒色になったら難所へ引き渡し
  while (!color.getBlackColor())
    ;
  /* 難所引き渡し */
  return true;
}
