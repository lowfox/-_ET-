#define DEBUG

#ifdef DEBUG
#include "GarageScene.h"
#include "Detech_mock.h"
#include "Steering_mock.h"
#include <RyujiEv3.h>
#include <Drive.h>
#else
#include "GarageScene.h"
#include <RyujiEv3.h>
#include <Drive.h>
#include <Detect.h>
#include <Steering.h>
#endif // DEBUG



GarageScene::GarageScene(ISceneChanger* sceneChanger) : IScene(sceneChanger)
{

}

bool GarageScene::init()
{
	return true;
}

bool GarageScene::run()
{
	// GarageCode
	garage_in aaa;

	aaa.blue_line_total_range_calculation();
	aaa.check_up_to_garage_in();
	aaa.provision_range_calculation();

	return change(SceneID::End);
}

void GarageScene::garage_in::blue_line_total_range_calculation()
{
	//���s���[�h�ݒ�
	Drive::SetDriveMode(DriveMode::LineTrace);

	//���s�J�n
	Drive::Drive(15);

	//���C���ɓ��B���������f
	Judgment = 0;

	while (Judgment == 0)
	{
		if (Detect::GetColor() == ReadColor::BLUE)
		{
			Judgment = 1;
		}
	}

	//�ŏ��̋����l�̕ۑ�
	Distance_initia = Steering::GetDistance();

	//���C���̑������Z�o
	Judgment = 0;
	while (Judgment == 0) {
		current_range_value = Steering::GetDistance();
		measuring_range_value = current_range_value - Distance_initia;

		if (Detect::GetColor() == ReadColor::BLACK) {
			Judgment = 1;
		}
	}
}

void GarageScene::garage_in::provision_range_calculation()
{
	//�䗦�萔
	const static int ratio = 0;
	//�����䗦�v�Z
	range_up_to_garage = measuring_range_value * ratio;
}

void GarageScene::garage_in::check_up_to_garage_in()
{
	//���苗������
	Judgment = 0;
	Distance_initia = Steering::GetDistance();
	measuring_range_value = 0;

	while (range_up_to_garage == measuring_range_value) {
		current_range_value = Steering::GetDistance();
		measuring_range_value = current_range_value - Distance_initia;
	}

	Drive::Stop();
}