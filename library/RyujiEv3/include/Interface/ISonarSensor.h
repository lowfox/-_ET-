///
/// @file ISonarSensor.h
/// @brief 超音波センサーへのインターフェース
///
#pragma once
#include "RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief SonarSensor Interface
	///
	class ISonarSensor
	{
	public:

		virtual ~ISonarSensor(){}
		
		///
		/// @fn int16 getDistance()
		/// @brief 距離を測定する
		/// @return int16 距離[cm]
		///
		virtual int16 getDistance() = 0;
	};
}