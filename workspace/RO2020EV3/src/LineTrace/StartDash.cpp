#include "StartDash.h"

StartDash::StartDash() {}

StartDash::~StartDash() {}


void StartDash::tailOperation() {
	// しっぽをあげる
	RyujiEv3Engine::GetTailMotor()->setCounts(-90, 50,true);      //Takeuchi(尻尾を90°上げる)
}

//int StartDash::gyroOffsetSetting() {}
