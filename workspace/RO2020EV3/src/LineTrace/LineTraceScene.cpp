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
	String pid("pid");
	// SetPIDコマンドを登録
	BluetoothCommandReceiver::add(pid, [](std::vector<const char*>& arg) {
		EV3_LOG("SetPID,%d,%d,%d", static_cast<float>(std::atof(arg[0]), static_cast<float>(std::atof(arg[1]), static_cast<float>(std::atof(arg[2])));
		Drive::LineTrace::SetPID({ static_cast<float>(std::atof(arg[0])), 
			static_cast<float>(std::atof(arg[1])), 
			static_cast<float>(std::atof(arg[2])) });
	});
	String set("speed");
	BluetoothCommandReceiver::add(set, [](std::vector<const char*>& arg) {
		EV3_LOG("SetSpeed %d",std::atoi(arg[0]));
		Drive::Drive(std::atoi(arg[0]));
	});

	BluetoothCommandReceiver::add("Test", setspeed);
  // LineTraceCode
  Standby stanby;       //Stanbyクラスのインスタンス生成

  stanby.traceMain();       //setup関数開始

  return change(LINETRACE_NEXT_SCENE);
}