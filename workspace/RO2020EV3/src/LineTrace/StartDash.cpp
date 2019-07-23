#include "StartDash.h"

StartDash::StartDash() {}

StartDash::~StartDash() {}


void StartDash::tailOperation() {
	// ‚µ‚Á‚Û‚ð‚ ‚°‚é
	RyujiEv3Engine::GetTailMotor()->setCounts(0, 50);
}

//int StartDash::gyroOffsetSetting() {}
