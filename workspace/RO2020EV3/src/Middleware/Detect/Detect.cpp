#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"

namespace Detect {
ReadColor GetColor(float blueCorr, float rgbCorr) {
  const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
  const TraceColor traceColor =
      DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

		const float gray = (traceColor.black + traceColor.white) / 2.0f;
		float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

		/// 青色検知
		if ((traceColor.blue.b * blueCorr) < rgb.b && (traceColor.blue.r * rgbCorr) > rgb.r && (traceColor.blue.g * rgbCorr) > rgb.g)
		{
			return ReadColor::BLUE;
		}
		/// 白検知
		else if (rgbAverage * 0.7f > gray)
		{
			return ReadColor::WHITE;
		}
		/// 黒検知
		else if (rgbAverage < gray && rgbAverage * 1.2f > rgb.b)
		{
			return ReadColor::BLACK;
		}
		/// 色なし
		else {
			return ReadColor::NONE;
        }
	}
}