///
/// @file TailControl.h
/// @brief 尻尾モータ管理
///

#pragma once
#include <RyujiEv3.h>
#include <Drive.h>
#include <Steering.h>
#include "Debug.h"

#define MIN_TARGET  55
#define MAX_TARGET  80
#define MAX_TARGET_BOUNDARY 2
#define ANGLE_ADJUST_1 2
#define ANGLE_ADJUST_2 3
#define ANGLE_ADJUST_VAL_1 1
#define ANGLE_ADJUST_VAL_2 2

class TailControl
{

private:
	 #ifdef __LOOKUP_DEBUG__
    bool StbAngle(int32 target_val,int32 speed = 30);
	#endif
	
public:
	///
    /// @fn bool Angle(int32 target_val)
	/// @brief 指定角度の後傾
	/// @retval true  成功
	/// @retval false 失敗
	///   
	bool Angle(int32 target_val,int32 speed = 30);
   

	///
	/// @fn bool StageAngle(int32 target_val)
	/// @brief 指定角度範囲の後傾
	/// @retval true  成功
	/// @retval false 失敗
	///   
	bool StageAngle(int32 target_val);
		
};

