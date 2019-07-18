///
/// @file TailControl.h
/// @brief 尻尾モータ管理
///

#pragma once
#include <RyujiEv3.h>
#include <Drive.h>
#include <Steering.h>
#include "Debug.h"

#define MIN_TARGET  53
#define MAX_TARGET  80

class TailControl
{
public:
	///
    /// @fn bool Angle(int32 target_val)
	/// @brief 指定角度の後傾
	/// @retval true  成功
	/// @retval false 失敗
	///   
	bool Angle(int32 target_val);

	///
	/// @fn bool StageAngle(int32 target_val)
	/// @brief 指定角度範囲の後傾
	/// @retval true  成功
	/// @retval false 失敗
	///   
	bool StageAngle(int32 target_val);
		
};

