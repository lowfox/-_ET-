//#define DEBUG
#define test
//#define nagisakun

#ifdef DEBUG
#include "GarageScene.h"
#include "Detect_mock.h"
#include "Steering_mock.h"
#include <RyujiEv3.h>
#include <Drive.h>
#else
#include "GarageScene.h"
#include <RyujiEv3.h>
#include <Drive.h>
#include <Detect.h>
#include <Steering.h>
#include <Logger.h>
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
	garage_in garage;

	garage.blue_line_total_range_calculation();
	garage.check_up_to_garage_in();
	garage.provision_range_calculation();

	return change(SceneID::End);
}

void GarageScene::garage_in::blue_line_total_range_calculation()
{
#ifdef test
	//�K���p�x�ݒ�
	//RyujiEv3Engine::GetTailMotor()->setCounts(-90, 50, true);
	RyujiEv3Engine::GetTailMotor()->setCounts(80, 50, true);      //Takeuchi(80�x������A������X�s�[�h�A�Ƃ肠��true)
#endif // test


	//���s���[�h�ݒ�
	Drive::SetDriveMode(DriveMode::LineTrace);
	
	//SetTraceColor�ǉ�//Takeuchi
	TraceColor traceColor;                      //Takeuchi
	
	//traceColor = Drive::ColorCalibrate::GetTraceColor(80);    //Takeuchi(Nomal Degree���ŏ��ɓo�^����Ă���̂�0�Ԗڂɓo�^���ꂽ�g���[�X�J���[���Ăяo��)
	traceColor = { 6.333, 78.333, {17,57,156} };
	Drive::LineTrace::SetTraceColor(traceColor);//Takeuchid

	Drive::LineTrace::SetPID({ 0.5f, 0.0f, 0.2f }); 

	Drive::Drive(10);
	
	//���C���ɓ��B���������f
	Judgment = 0;
	
	while (Judgment == 0)
	{
		//���s�J�n
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

		if (Detect::GetColor() == ReadColor::BLACK)
		{
			Judgment = 1;
		}
	}

	EV3_LOG("%f������", measuring_range_value);
}

void GarageScene::garage_in::provision_range_calculation()
{
	//�䗦�萔
	const static int ratio = 0.5;
	//�����䗦�v�Z
	range_up_to_garage = measuring_range_value * ratio;

	EV3_LOG("%f�䗦", range_up_to_garage);
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










