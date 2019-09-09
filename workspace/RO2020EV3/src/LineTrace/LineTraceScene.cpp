#include "LineTraceScene.h"
#include <Config.h>
#include "Standby.h"
#include <BluetoothCommandReceiver.h>
#include <Drive.h>
#include <Logger.h>
LineTraceScene::LineTraceScene(ISceneChanger* sceneChanger)
  : IScene(sceneChanger) {}

bool LineTraceScene::init() { return true; }

void setspeed(std::vector<String>& arg)
{
	EV3_LOG("SetSpeed", static_cast<int32>(std::atoi(arg[0].c_str())));
	Drive::Drive(std::atoi(arg[0].c_str()));
}

bool LineTraceScene::run() {
	// SetPID�R�}���h��o�^
	BluetoothCommandReceiver::add("SetPID", [](std::vector<String>& arg) {
		EV3_LOG("SetPID");
		Drive::LineTrace::SetPID({ static_cast<float>(std::atof(arg[0].c_str())), 
			static_cast<float>(std::atof(arg[1].c_str())), 
			static_cast<float>(std::atof(arg[2].c_str())) });
	});

	BluetoothCommandReceiver::add("SetSpeed", [](std::vector<String>& arg) {
		EV3_LOG("SetSpeed");
		Drive::Drive(std::atoi(arg[0].c_str()));
	});

	BluetoothCommandReceiver::add("II", setspeed);
  // LineTraceCode
  Standby stanby;       //Stanby�N���X�̃C���X�^���X����

  stanby.traceMain();       //setup�֐��J�n

  return change(LINETRACE_NEXT_SCENE);
}