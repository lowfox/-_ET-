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

  // SetTraceColor追加//Takeuchi
  TraceColor traceColor;  // Takeuchi
  traceColor = Drive::ColorCalibrate::GetTraceColor(
      90);  // Takeuchi(Nomal Degree(90°)で登録されたトレースカラーを呼び出し)
  Drive::LineTrace::SetTraceColor(traceColor);  // Takeuchi

  //トレースカラーがセットされてるかの確認//Takeuchi
  //セットしたはずのトレースカラー//Takeuchi

  //実際にセットされているセットカラー//Takeuchi
  traceColor = Drive::LineTrace::
      GetTraceColor();  // Takeuchi(現在セットされているトレースカラーを取得)//Takeuchi

  // StartDash
  dash.startRun();

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
//    m_runState = control.drivePosition();       //****************************旧PID&スピード状態遷移（コメントアウト！）

    if (m_runState == -1) {
      break;
    }
    //走行状態でPIDを切り替える
//    trace.lineTraceDrive(m_runState);            //****************************旧PID&スピード動的セット（コメントアウト！）
    Drive::LineTrace::SetPID({0.4f, 0.0f, 0.3f});  //****************************一律セットPID（経験則から最も多くのカーブに対応するもの）
    Drive::Drive(65);                              //****************************一律セットスピード(0～100)


  } while (true);
  EV3_LOG("GOOOOOOL");


  
  Drive::LineTrace::SetPID({0.4f, 0.0f, 0.2f});
  Drive::Drive(30);
  //  RyujiEv3Engine::GetSpeaker()->playTone(1000, 1000);
  Drive::LineTrace::SetLineMode(BlueLineMode::Blue);

  // 青線検知
  while (!color.getBlueColor()) {
    dly_tsk(100);
  };
  //  RyujiEv3Engine::GetSpeaker()->playTone(700, 1000);

  // 30%走行
  // Drive::Drive(m_lowSpeed);
  EV3_LOG("Im blue now");  // Takeuchi
  // ラインが黒色になったら難所へ引き渡し
  while (!color.getBlackColor()) {
    dly_tsk(100);
  };
  EV3_LOG("LineTrace End");
  /* 難所引き渡し */
  return true;
}
