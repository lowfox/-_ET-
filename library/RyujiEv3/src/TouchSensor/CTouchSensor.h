#pragma once
#include <Interface/ITouchSensor.h>
#include <RyujiEv3Port.h>

namespace RyujiEv3
{
	class CTouchSensor :public ITouchSensor
	{
	private:

		SensorPort port;

		bool m_click = false;

		bool m_pressing = false;

		bool m_clicked = false;

	public:

		bool init(SensorPort port);

		bool click()override;

		bool clicked()override;

		bool pressing()override;

		bool update()override;
	};
}