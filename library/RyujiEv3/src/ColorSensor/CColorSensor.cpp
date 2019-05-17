#include "CColorSensor.h"
#include <ev3api.h>

namespace RyujiEv3
{
	bool CColorSensor::init(SensorPort port)
	{
		auto result = ev3_sensor_config(static_cast<sensor_port_t>(port), COLOR_SENSOR);

		if (result != E_OK)
		{
			return false;
		}

		this->port = port;

		return true;
	}

	uint8 CColorSensor::getReflect()
	{
		return ev3_color_sensor_get_reflect(static_cast<sensor_port_t>(port));
	}
}