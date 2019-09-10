///
/// @file Detect.h
/// @brief 検知関数
///
#pragma once
#include <RyujiEv3.h>

namespace Detect {
///
/// @fn ReadColor getColor(float blueCorr = 0.7, float rgbCorr = 0.6)
/// @brief 現在のラインの色を取得する
/// @param blueCorr セットされたTraceColor青の補正値、下げるほど検知しやすくなる
/// @param rgbCorr 取得した色のRGBの補正値、下げるほど検知しやすくなる
/// @return 現在のラインの色
///
ReadColor GetColor(float blueCorr = 0.7, float rgbCorr = 0.6);
}  // namespace Detect