#include "LineTraceScene.h"
#include <Config.h>
#include "Standby.h"
#include <BluetoothCommandReceiver.h>
#include <Drive.h>
#include <Logger.h>
LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

void setspeed(std::vector<const char*>& arg)
{
	EV3_LOG("SetSpeed arg = %d", static_cast<int32>(std::atoi(arg[0])));
	Drive::Drive(static_cast<int32>(std::atoi(arg[0])));
}

bool LineTraceScene::run() {
	// SetPIDコマンドを登録
	BluetoothCommandReceiver::add("SetPID", [](std::vector<const char*>& arg) {
		EV3_LOG("SetPID");
		Drive::LineTrace::SetPID({ static_cast<float>(std::atof(arg[0])), 
			static_cast<float>(std::atof(arg[1])), 
			static_cast<float>(std::atof(arg[2])) });
	});

	BluetoothCommandReceiver::add("SetSpeed", [](std::vector<const char*>& arg) {
		EV3_LOG("SetSpeed");
		Drive::Drive(std::atoi(arg[0]));
	});

	BluetoothCommandReceiver::add("Test", setspeed);
  // LineTraceCode
  Standby stanby;       //Stanbyクラスのインスタンス生成

  stanby.traceMain();       //setup関数開始

  return change(LINETRACE_NEXT_SCENE);
}