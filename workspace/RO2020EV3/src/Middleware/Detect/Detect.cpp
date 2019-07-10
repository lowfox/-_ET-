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

		// ÂŒŸ’m
		if ((traceColor.blue.b * 0.7) < rgb.b && (rgb.r + rgb.g) * 0.6 < rgb.b)
		{
			return ReadColor::BLUE;
		}
		// ”’ŒŸ’m
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