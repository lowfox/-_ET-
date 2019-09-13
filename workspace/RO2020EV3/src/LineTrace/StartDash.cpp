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
  
  Drive::LineTrace::SetLineMode(BlueLineMode::Nomal);
  Drive::SetDriveMode(DriveMode::Nomal); // ライントレースモードオフ

  // スタートが安定するまでライントレースをせずに前進する
  Drive::LineTrace::SetPID({0.0f, 0.0f, 0.0f});
  // 速度0でも前傾姿勢のため走る
  Drive::Drive(0);
  // 尻尾を少し下ろし前傾姿勢にする
  RyujiEv3Engine::GetTailMotor()->setCounts(5, 20, false);
  Steering::SetMode(SteeringMode::Balance);  // 倒立モード
  RyujiEv3Engine::GetTailMotor()->setCounts(-90, 10, true);

  dly_tsk(400);
  Drive::SetDriveMode(DriveMode::LineTrace);
  Drive::LineTrace::SetPID({0.1f, 0.0f, 0.05f});
  dly_tsk(1000);
  Drive::Drive(100);
}
