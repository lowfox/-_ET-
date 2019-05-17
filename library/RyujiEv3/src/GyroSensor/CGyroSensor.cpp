#include "CGyroSensor.h"
#include <ev3api.h>

namespace RyujiEv3
{
	bool CGyroSensor::init(SensorPort port)
	{
		auto result = ev3_sensor_config(static_cast<sensor_port_t>(port), GYRO_SENSOR);

		if (result != E_OK)
		{
			return false;
		}
		this->port = port;

		return true;
	}

	void CGyroSensor::setOffset(int32 offset)
	{
		m_offset = offset;
	}

	int32 CGyroSensor::getOffset()
	{
		return m_offset;
	}

	int16 CGyroSensor::getAngle()
	{
		return ev3_gyro_sensor_get_angle(static_cast<sensor_port_t>(port));
	}

	int16 CGyroSensor::getRate()
	{
		return ev3_gyro_sensor_get_rate(static_cast<sensor_port_t>(port))+m_offset;
	}

	bool CGyroSensor::reset()
	{
		auto result =  ev3_gyro_sensor_reset(static_cast<sensor_port_t>(port));

		if (result != E_OK)
		{
			return false;
		}

		return true;
	}
}