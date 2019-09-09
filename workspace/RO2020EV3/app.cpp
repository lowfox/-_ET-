#include <ev3api.h>
#include "app.h"
#include <RyujiEv3.h>
#include <System.h>
#include <Logger.h>
#include <SceneManager.h>
#include <Config.h>
#include <BluetoothCommandReceiver.h>

// main Task
void main_task(intptr_t unused)
{
	// API,�~�h���E�F�A ������
	if (!System::Init(ROBOCON_PORT))
	{
		System::Exit();
		ext_tsk();
		return;
	}
	
	// BluetoothTask�N��
	act_tsk(BT_TASK);

	// RoboconTask�N��
	act_tsk(ROBOCON_TASK);

	// �����̃{�^���������Ƌ����I��
	while (!ev3_button_is_pressed(ENTER_BUTTON))
	{
		tslp_tsk(100);
	}

	// BluetoothTask�����I��
	ter_tsk(BT_TASK);

	// RoboconTask�����I��
	ter_tsk(ROBOCON_TASK);

	// API,�~�h���E�F�A �I������
	System::Exit();

}

// robocon_task
void robocon_task(intptr_t exinf)
{
	EV3_LOG_INFO("robocon_task Start");

	SceneManager sceneManager;

	sceneManager.init(START_SCENE_ID);

	while (sceneManager.isEnable())
	{
		if (!sceneManager.run())
		{
			break;
		}
	}

	EV3_LOG_INFO("robocon_task End");

	// ���^�X�N���I��
	ext_tsk();
}

// Bluetooth Task
void bt_task(intptr_t unused)
{
	EV3_LOG_INFO("bt_task Start");

	BluetoothCommandReceiver::init();

	while (true)
	{
		dly_tsk(1);
		BluetoothCommandReceiver::update();
	}

	EV3_LOG_INFO("bt_task End");

	// ���^�X�N���I��
	ext_tsk();

// clang-format off
}]