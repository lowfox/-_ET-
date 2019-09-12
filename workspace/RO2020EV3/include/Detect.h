///
/// @file Detect.h
/// @brief 検知関数
///
#pragma once
#include <RyujiEv3.h>

namespace Detect
{
	///
	/// @fn ReadColor getColor()
	/// @brief 現在のラインの色を取得する
	/// @return 現在のラインの色
	///
	ReadColor GetColor();
}
