#include <Detect.h>
#include "../Drive/DriveManager.h"
#include "../DriveEngine/DriveEngine.h"
#include <algorithm>
#include <Logger.h>
#include <vector>
namespace Detect {
ReadColor GetColor(float blueCorr, float rgbCorr) {
  const RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
  const TraceColor traceColor =
      DriveEngine::GetDrive()->getLineTraceDrive()->getTraceColor();

  const float gray = (traceColor.black + traceColor.white) / 2.0f;
  float rgbAverage = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);

  /// 青色検知
  if ((traceColor.blue.b * blueCorr) < rgb.b &&
      (traceColor.blue.r * rgbCorr) > rgb.r &&
      (traceColor.blue.g * rgbCorr) > rgb.g) {
    return ReadColor::BLUE;
  }
  /// 白検知
  else if (rgbAverage * 0.7f > gray) {
    return ReadColor::WHITE;
  }
  /// 黒検知
  else if (rgbAverage < gray && rgbAverage * 1.2f > rgb.b) {
    return ReadColor::BLACK;
  }
  /// 色なし
  else {
    return ReadColor::NONE;
  }
}

ReadColor GetColorHSV() {
  RGB rgb = RyujiEv3Engine::GetColorSensor()->getRGB();
  // HSVに変換
  float max = 0;
  float min = 0;
  int h     = 0;
  float s   = 0;
  uint16 v  = 0;
  //最大値求める
  max = rgb.r;
  if (max < rgb.g) {
    max = rgb.g;
  }
  if (max < rgb.b) {
    max = rgb.b;
  }
  //最小値を求める
  min = rgb.r;
  if (min > rgb.g) {
    min = rgb.g;
  }
  if (min > rgb.b) {
    min = rgb.b;
  }
  // H色相を求める
  if (max == rgb.r) {
    h = 60 * ((rgb.g - rgb.b) / (max - min));
  }
  if (max == rgb.g) {
    h = 60 * ((rgb.b - rgb.r) / (max - min)) + 120;
  }
  if (max == rgb.b) {
    h = 60 * ((rgb.r - rgb.g) / (max - min)) + 240;
  }
  if (rgb.r == rgb.b && rgb.r == rgb.g) {
    h = 0;
  }
  if (h < 0) {
    h += 360;
  }

  // S彩度を求める
  s = ((max - min) / max);
  s = s * 100;
  // V明度
  v = max;

  //  EV3_LOG_DEBUG("r=%d g=%d b=%d   |  h=%d s=%f v=%d", rgb.r, rgb.g, rgb.b,
  //  h, s,
  //               v);

  if (h < 110 && v < 82) {
    return ReadColor::BLACK;
  } else if (h >= 111) {
    return ReadColor::BLUE;
  }  // else if (s >= 50 || h < 90 && s < 30) {
  else {
    return ReadColor::WHITE;
  }
}
}  // namespace Detect