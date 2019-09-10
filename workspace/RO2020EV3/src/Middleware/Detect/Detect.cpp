#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"

namespace Detect {
ReadColor GetColor(float blueCorr, float rgbCorr) {
  const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
  const TraceColor traceColor =
      DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

  const float gray = (traceColor.black + traceColor.white) / 2.0f;

  /// 青色検知
  if ((traceColor.blue.b * blueCorr) < rgb.b &&
      (rgb.r + rgb.g) * rgbCorr < rgb.b) {
    return ReadColor::BLUE;
  }
  /// 白検知
  else if ((static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f) > gray) {
    return ReadColor::WHITE;
  }
  /// 黒検知
  else {
    return ReadColor::BLACK;
  }
}
}  // namespace Detect