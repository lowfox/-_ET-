#pragma once
#include "Interface/IColorSensor.h"
#include "RyujiEv3Port.h"

namespace RyujiEv3
{
	class CColorSensor :public IColorSensor
	{
	private:

		SensorPort port;

	public:

		bool init(SensorPort port);

		uint8 getReflect()override;
	};
}