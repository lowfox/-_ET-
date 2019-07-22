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
	//走行モード設定
	Drive::SetDriveMode(DriveMode::LineTrace);

	//走行開始
	Drive::Drive(15);

	//青ラインに到達したか判断
	Judgment = 0;

	while (Judgment == 0)
	{
		if (Detect::GetColor() == ReadColor::BLUE)
		{
			Judgment = 1;
		}
	}

	//最初の距離値の保存
	Distance_initia = Steering::GetDistance();

	//青ラインの総距離算出
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
	//比率定数
	const static int ratio = 0;
	//距離比率計算
	range_up_to_garage = measuring_range_value * ratio;
}

void GarageScene::garage_in::check_up_to_garage_in()
{
	//既定距離測定
	Judgment = 0;
	Distance_initia = Steering::GetDistance();
	measuring_range_value = 0;

	while (range_up_to_garage == measuring_range_value) {
		current_range_value = Steering::GetDistance();
		measuring_range_value = current_range_value - Distance_initia;
	}

	Drive::Stop();
}