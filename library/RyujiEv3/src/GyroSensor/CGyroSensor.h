#pragma once
#include "Interface/IGyroSensor.h"
#include "RyujiEv3Port.h"

namespace RyujiEv3
{
	class CGyroSensor :public IGyroSensor
	{
	private:

		SensorPort port;

		int32 m_offset = 0;

	public:

		bool init(SensorPort port);

		void setOffset(int32 offset)override;

		int32 getOffset()override;

		int16 getAngle()override;

		int16 getRate()override;

		bool reset()override;
	};
}