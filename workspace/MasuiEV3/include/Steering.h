///
/// @file Steering.h
/// @brief ステアリング
///
#pragma once
#include <RyujiEv3.h>

/// ステアリングモード
enum class SteeringMode
{
	/// 倒立モード
	Balance,

	/// 通常モード
	Nomal
};

namespace Steering
{
	///
	/// @fn void SetMode(SteeringMode mode)
	/// @brief ステアリングモードを指定する
	/// @param mode ステアリングモード
	/// @retval true 成功
	/// @retval false 失敗
	///
	bool SetMode(SteeringMode mode);

	///
	/// @fn float GetDistance()
	/// @brief 起動時からの走行距離を取得する
	/// @return 走行距離[mm]
	///
	float GetDistance();
}