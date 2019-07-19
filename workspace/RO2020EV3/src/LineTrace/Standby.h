#pragma once
#include <RyujiEv3.h>

#define NomalDeg 90
#define LookUp_1Deg 80
#define LookUp_2Deg 62
#define Seesaw_1Deg 65
#define Seesaw_2Deg 70
#define Seesaw_3Deg 75

//ライントレーススタンバイ
class Standby
{
public:
	Standby();
	~Standby();

	void traceMain();

	void setup();

private:
	void Calibration(int);

	bool buttonDetection();

	bool bluetoothDetection();

	void runStart();

};

