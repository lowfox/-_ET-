#include "Standby.h"
#include "Run.h"
#include <Drive.h>

auto* tail = RyujiEv3Engine::GetTailMotor();
auto* touch = RyujiEv3Engine::GetTouchSensor();
auto* speaker = RyujiEv3Engine::GetSpeaker();
auto* lcd = RyujiEv3Engine::GetLCD();
auto* Bluetooth = RyujiEv3Engine::GetBluetooth();


Standby::Standby() {}

Standby::~Standby() {}

void Standby::traceMain() {
	setup();

	while (1) {
		if (bluetoothDetection() == true) { break; }
		if ((buttonDetection() == true) && (Bluetooth->isConnected() == false)) { break; }
	}

	runStart();
}

void Standby::setup() {
	//尻尾角度のリセット
	tail->resetCounts();//尻尾を上にあげきった状態で実行

//キャリブレーション
	/* 直立 */
	tail->setCounts(NomalDeg, 70, true);
	Calibration(NomalDeg);

	/* ルックアップ1 */
	tail->setCounts(LookUp_1Deg, 70, true);
	Calibration(LookUp_1Deg);
	/* ルックアップ2 */
	tail->setCounts(LookUp_2Deg, 70, true);
	Calibration(LookUp_2Deg);

	/* シーソー1 */
	tail->setCounts(Seesaw_1Deg, 70, true);
	Calibration(Seesaw_1Deg);
	/* シーソー2 */
	tail->setCounts(Seesaw_2Deg, 70, true);
	Calibration(Seesaw_2Deg);
	/* シーソー3 */
	tail->setCounts(Seesaw_3Deg, 70, true);
	Calibration(Seesaw_3Deg);
}

void Standby::Calibration(int Deg) {
	TraceColor countColor;

	//黒
	lcd->drawString(0, 0, "GetColor : Bkack : %d", Deg);
	do {
		touch->update();
	} while (!touch->clicked());
	RGB rgb = Drive::ColorCalibrate::RGBAverage1Sec();
	countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
	speaker->playTone(600, 1);

	//白
	lcd->drawString(0, 0, "GetColor : White : %d", Deg);
	do {
		touch->update();
	} while (!touch->clicked());
	rgb = Drive::ColorCalibrate::RGBAverage1Sec();
	countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
	speaker->playTone(600, 1);

	//青
	lcd->drawString(0, 0, "GetColor : Bkack : %d", Deg);
	do {
		touch->update();
	} while (!touch->clicked());
	countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
	speaker->playTone(600, 1);

	Drive::ColorCalibrate::AddTraceColor(Deg, countColor);
}

bool Standby::bluetoothDetection() {
	unsigned int tooth = 1;

	//Bluetooth信号、受け取ったらtrueをリターン
	while (1) {
		if (Bluetooth->read() == tooth) { break; }
	}

	return true;
}

bool Standby::buttonDetection() {

	//Button、押されたらtrueをリターン
	do {
		touch->update();
	} while (!touch->clicked());

	return true;
}

void Standby::runStart() {
	Run start;
	start.driveStart();
}
