///
/// @file Detect.h
/// @brief 検知関数
///
#pragma once
#include <RyujiEv3.h>
namespace Detect
{
	///
	/// @fn ReadColor getColor(float blueCorr = 0.7, float rgbCorr = 1.3)
	/// @brief 現在のラインの色を取得する
	/// @param blueCorr セットされたTraceColor青の補正値、下げるほど検知しやすくなる
	/// @param rgbCorr 取得した色のRGBの補正値、上げるほど検知しやすくなる
	/// @return 現在のラインの色
	///
	ReadColor GetColor(float blueCorr = 0.7f, float rgbCorr = 1.3f);

	///
	/// @fn ReadColor getColorHSV()
	/// @brief 現在のラインの色を取得する(現在、青・白・黒のみ)
	/// @return 現在のラインの色
	///
	ReadColor GetColorHSV();
}
