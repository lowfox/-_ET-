#include "StartDash.h"
#include <Drive.h>
#include <Steering.h>
#include <Logger.h>
#include "Detect.h"

StartDash::StartDash() {}

StartDash::~StartDash() {}

void StartDash::startRun() {
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  EV3_LOG("StartDash_Start\n");
  speaker->setVolume(100);
  
  EV3_LOG("Tail01 %d \n", RyujiEv3Engine::GetTailMotor()->getCounts());


  Drive::LineTrace::SetLineMode(BlueLineMode::Nomal);
  Drive::SetDriveMode(DriveMode::Nomal); // ライントレースモードオフ
  EV3_LOG("Trace Off\n");
  // スタートが安定するまでライントレースをせずに前進する
  Drive::LineTrace::SetPID({0.0f, 0.0f, 0.0f});
  // 速度0でも前傾姿勢のため走る
  Drive::Drive(0);
  EV3_LOG("No Trace Go\n");
  // 尻尾を少し下ろし前傾姿勢にする
  RyujiEv3Engine::GetTailMotor()->setCounts(5, 20, false);
  EV3_LOG("Tail 5 20 false\n");
  Steering::SetMode(SteeringMode::Balance);  // 倒立モード
  EV3_LOG("SteeringMode Balance\n");
  RyujiEv3Engine::GetTailMotor()->setCounts(-88, 10, true);
  EV3_LOG("Tail -90 10 false\n");

  Drive::SetDriveMode(DriveMode::LineTrace);
  EV3_LOG("LineTraceMode ON\n");
  Drive::LineTrace::SetPID({0.1f, 0.0f, 0.05f});
  Drive::Drive(30);
  dly_tsk(800);
  Drive::Drive(50);
  dly_tsk(300);
  EV3_LOG("Set PID And Deley 1000\n");
  EV3_LOG("StartDash_End\n");
}
