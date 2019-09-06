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
#include "Standby.h"
#endif // DEBUG

GarageScene::GarageScene(ISceneChanger* sceneChanger) : IScene(sceneChanger)
{

}

bool GarageScene::init()
{
	Standby stanby;       //for test only
	stanby.traceMain();   //for test only
	RyujiEv3Engine::GetTailMotor()->setCounts(80, 50, true); //for test only
	return true;
}

bool GarageScene::run()
{
	// GarageCode
	garage_in garage;
	garage.Start_Process();
	return change(SceneID::End);
}

void GarageScene::garage_in::Start_Process()
{
#ifdef test
	//�K���p�x�ݒ�
	//RyujiEv3Engine::GetTailMotor()->setCounts(-90, 50, true);
	//RyujiEv3Engine::GetTailMotor()->setCounts(80, 50, true);      //Takeuchi(80�x������A������X�s�[�h�A�Ƃ肠��true)
#endif // test

	if (!RyujiEv3Engine::GetLeftMotor()->stop(true)) {
		EV3_LOG("GET_LEFT_ERR");
	}
	if (!RyujiEv3Engine::GetRightMotor()->stop(true)) {
		EV3_LOG("GET_RIGHT_ERR");
	}

	TraceColor traceColor;                      //Takeuchi

	/*RGB RGB_COLOR;  //only used for test
	while (1) {
		RGB_COLOR=RyujiEv3Engine::GetColorSensor()->getRGB();

		if (Detect::GetColor() == ReadColor::BLUE)
		{
			EV3_LOG("BLUE");
		}

		else if (Detect::GetColor() == ReadColor::BLACK)
		{
			EV3_LOG("BLACK");
		}

		else {
			EV3_LOG("WHITE");
		}
	}*/
	
	//���s���[�h�ݒ�
	if (!Drive::SetDriveMode(DriveMode::LineTrace)) {
		EV3_LOG("SetDriveMode...false");
	}

	traceColor = Drive::ColorCalibrate::GetTraceColor(80);    //Takeuchi(Nomal Degree���ŏ��ɓo�^����Ă���̂�0�Ԗڂɓo�^���ꂽ�g���[�X�J���[���Ăяo��)
	EV3_LOG("BLACK=%f \n WHITE%f\n BLUE.R=%d\n BLUE.G=%d\n BLUE.B=%d",traceColor.black,traceColor.white, traceColor.blue.r, traceColor.blue.g, traceColor.blue.b);
	Drive::LineTrace::SetTraceColor(traceColor);//Takeuchid
	
	Drive::LineTrace::SetPID({ 0.2f, 0.0f, 0.1f });

	if (!Drive::Drive(5)) {
		EV3_LOG("SetDriveSet...false");
	}
	
	if (!RyujiEv3Engine::GetSpeaker()->setVolume(100)) {
		EV3_LOG("SetGetSpeaker...false");
	}
	//���C���ɓ��B���������f
	while (1)
	{
		EV3_LOG("NOT_BLUE");
		//���s�J�n
		if (Detect::GetColor() == ReadColor::BLUE)
		{
			EV3_LOG("BLUE_GET");
			/* �����ŉ���炷 */
			if (!RyujiEv3Engine::GetSpeaker()->playTone(500, 500)) {
				EV3_LOG("SPEAKER_ERR");
			}
			break;
		}
	}
	
	//�ŏ��̋����l�̕ۑ�	//�������C���ւ̕ω������
	while ( 1 ) {
		EV3_LOG("NOT_BLACK");
		/* �����֕ω��������A�����Ǝ��@�̋����������߂� */
		if (Detect::GetColor() == ReadColor::BLACK)
		{
			EV3_LOG("BLACK_GET");
			/* �����ŉ���炷 */
			if (!RyujiEv3Engine::GetSpeaker()->playTone(500, 500)) {
				EV3_LOG("SPEAKER_ERR");
			}
			Initial_Distance = Steering::GetDistance();
			break;
		}
	}

	while ((Initial_Distance + 150.0f) > Steering::GetDistance()) {}
	Drive::Stop();
	EV3_LOG("FINISHED");
	RyujiEv3Engine::GetSpeaker()->playTone(500, 1000);
}