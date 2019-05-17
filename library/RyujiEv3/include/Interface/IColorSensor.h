///
/// @file IColorSensor.h
/// @brief カラーセンサーへのインターフェース
///
#pragma once

#include "../RyujiEv3Forward.h"

namespace RyujiEv3
{
    ///
	/// @brief ColorSensor Interface
	///	
	class IColorSensor
	{
	public:

		virtual ~IColorSensor(){}
		
		///
		/// @fn uint8 getReflect()
		/// @brief 反射光の強さを取得する
		/// @return uint8 反射光(0 ～ 100)
		///
		virtual uint8 getReflect() = 0;
	};
}
