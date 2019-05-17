///
/// @file IGyroSensor.h
/// @brief ジャイロセンサーへのインターフェース
///
#pragma once
#include "RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief GyroSensor Interface
	///	
	class IGyroSensor
	{
	public:

		virtual ~IGyroSensor() {}

		///
		/// @fn void setOffset(int32 offset)
		/// @brief オフセットを設定する
		/// @param offset オフセット値
		///
		virtual void setOffset(int32 offset) = 0;

		///
		/// @fn int32 getOffset()
		/// @brief 設定されているオフセットを取得する
		/// @return int32 設定されているオフセット値
		///
		virtual int32 getOffset() = 0;

		///
		/// @fn int16 getAngle()
		/// @brief 角位置を測定する
		/// @return int16 角位置（度）
		///
		virtual int16 getAngle() = 0;

		///
		/// @fn int16 getRate()
		/// @brief 角速度を測定する
		/// @return int16 角位置（度/秒）
		///
		virtual int16 getRate() = 0;

		///
		/// @fn bool reset()
		/// @brief 角位置をゼロにリセットする
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool reset() = 0;
	};
}