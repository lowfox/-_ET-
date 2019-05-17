#pragma once
#include <Interface/IMotor.h>
#include <RyujiEv3Port.h>
namespace RyujiEv3
{
	class CMotor :public IMotor
	{
	private:

		MotorPort port;

	public:

		bool init(MotorPort port);

		int32 getCounts()override;

		int32 getPWM()override;

		bool resetCounts()override;

		bool setCounts(int32 degree,int32 speed, bool blocking = false)override;

		bool setPWM(int32 power)override;

		bool stop(bool brake = false)override;
	};
}