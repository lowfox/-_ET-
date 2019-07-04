#include "NomalSteering.h"

bool NomalSterring::init()
{
	return drive(0, 0);
}

bool NomalSterring::drive(int32 speed, int32 turn)
{
	if (!RyujiEv3Engine::GetLeftMotor()->setPWM(speed + turn))
	{
		return false;
	}

	if (!RyujiEv3Engine::GetRightMotor()->setPWM(speed - turn))
	{
		return false;
	}

	return true;
}

bool NomalSterring::stop()
{
	if (!RyujiEv3Engine::GetLeftMotor()->stop(true))
	{
		return false;
	}

	if (!RyujiEv3Engine::GetRightMotor()->stop(true))
	{
		return false;
	}

	return true;
}
