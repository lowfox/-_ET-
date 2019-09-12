#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"

namespace Detect
{
	ReadColor GetColor()
	{
		const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
		const TraceColor traceColor = DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

  const float gray = (traceColor.black + traceColor.white) / 2.0f;
  float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

		// ���m
		if ((rgb.r + rgb.g) < rgb.b)
		{
			return ReadColor::BLUE;
		}
		// �����m
		else if ((rgb.r + rgb.g + rgb.b) / 3 > gray)
		{
			return ReadColor::WHITE;
		}
		else
		{
			return ReadColor::BLACK;
		}
	}
}
