#include "BalanceSteering.h"

bool BalanceSterring::init()
{
	leftMotor  = RyujiEv3Engine::GetLeftMotor();
	rightMotor = RyujiEv3Engine::GetRightMotor();

	leftPWM = 0;
	rightPWM = 0;

	if (!leftMotor->resetCounts())
	{
		return false;
	}

	if (!rightMotor->resetCounts())
	{
		return false;
	}

	if (!RyujiEv3Engine::GetGyroSensor()->reset())
	{
		return false;
	}

	balance_init();

	return true;
}

bool BalanceSterring::drive(int32 speed, int32 turn)
{
	m_speed = speed;
	m_turn  = turn;

	return true;
}

bool BalanceSterring::stop()
{
	m_speed = 0;
	m_turn  = 0;

	return true;
}

bool BalanceSterring::update()
{
	int32 leftCounts  = leftMotor->getCounts();
	int32 rightCounts = rightMotor->getCounts();

	backlash_cancel(leftPWM, rightPWM, &leftCounts, &rightCounts);

	balance_control(
		static_cast<float>(m_speed),
		static_cast<float>(m_turn),
		static_cast<float>(RyujiEv3Engine::GetGyroSensor()->getRate()),
		static_cast<float>(0),
		static_cast<float>(leftCounts),
		static_cast<float>(rightCounts),
		static_cast<float>(RyujiEv3Engine::GetBattery()->get_mV()),
		&leftPWM,
		&rightPWM
	);

	if (!leftMotor->setPWM(leftPWM))
	{
		return false;
	}

	if (!rightMotor->setPWM(rightPWM))
	{
		return false;
	}

	return true;
}
