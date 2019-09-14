#include "GarageScene.h"
#include <RyujiEv3.h>
#include <Drive.h>
#include <Detect.h>
#include <Steering.h>
#include <Logger.h>


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
	garage.Start_Process();
	return change(SceneID::End);
}

void GarageScene::garage_in::Start_Process()
{
	Drive::LineTrace::SetLineMode(BlueLineMode::Blue);
	if (!RyujiEv3Engine::GetLeftMotor()->stop(true)) {
		EV3_LOG("GET_LEFT_ERR");
	}
	if (!RyujiEv3Engine::GetRightMotor()->stop(true)) {
		EV3_LOG("GET_RIGHT_ERR");
	}

	TraceColor traceColor;                



	
	if (!Drive::SetDriveMode(DriveMode::LineTrace)) {
		EV3_LOG("SetDriveMode...false");
	}

	traceColor = Drive::ColorCalibrate::GetTraceColor(80);    
	EV3_LOG("BLACK=%f \n WHITE%f\n BLUE.R=%d\n BLUE.G=%d\n BLUE.B=%d",traceColor.black,traceColor.white, traceColor.blue.r, traceColor.blue.g, traceColor.blue.b);
	Drive::LineTrace::SetTraceColor(traceColor);
	
	Drive::LineTrace::SetPID({ 0.7f, 0.0f, 0.4f });

	if (!Drive::Drive(8)) {
		EV3_LOG("SetDriveSet...false");
	}
	
	if (!RyujiEv3Engine::GetSpeaker()->setVolume(100)) {
		EV3_LOG("SetGetSpeaker...false");
	}

	while (1)
	{
		EV3_LOG("NOT_BLUE");
		if (Detect::GetColor() == ReadColor::BLUE)
		{
			EV3_LOG("BLUE_GET");
			
			if (!RyujiEv3Engine::GetSpeaker()->playTone(500, 500)) {
				EV3_LOG("SPEAKER_ERR");
				//青検知のスタート位置
				Initial_Distance = Steering::GetDistance();
			}
			break;
		}
	}
	
	while ( 1 ) {
		EV3_LOG("NOT_BLACK");
		
		if (Detect::GetColor() == ReadColor::BLACK && ((Initial_Distance + 60.0f) < Steering::GetDistance()))
		{
			EV3_LOG("BLACK_GET");
			if (!RyujiEv3Engine::GetSpeaker()->playTone(500, 500)) {
				EV3_LOG("SPEAKER_ERR");
			}
			//黒検知のスタート位置
			Initial_Distance = Steering::GetDistance();
			break;
		}
	}

	while ((Initial_Distance + 100.0f) > Steering::GetDistance());
	Drive::Stop();
	EV3_LOG("FINISHED");
	RyujiEv3Engine::GetSpeaker()->playTone(500, 1000);
	if (!Drive::SetDriveMode(DriveMode::Nomal)){
		EV3_LOG("Set_NORMAL_ERR");
	}
}