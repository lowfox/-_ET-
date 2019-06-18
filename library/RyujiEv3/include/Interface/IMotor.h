///
/// @file IMotor.h
/// @brief モーターへのインターフェース
///
#pragma once
#include "../RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief Motor Interface
	///
	class IMotor
	{
	public:

		virtual ~IMotor(){}

		///
		/// @fn int32 getCounts()
		/// @brief モーターの回転角度を取得する
		/// @return int32 回転角度(度)
		///
		virtual int32 getCounts() = 0;

		///
		/// @fn int32 getPWM()
		/// @brief 現在のPWM出力値を取得する
		/// @return int32 PWM出力値
		///
		virtual int32 getPWM() = 0;

		///
		/// @fn bool resetCounts()
		/// @brief回転角度を0にする
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool resetCounts() = 0;

		///
		/// @fn bool setCounts(int32 degree,int32 speed, bool blocking = false)
		/// @brief モーターを指定角度で回転させる
		/// @param degree 回転角度 -で反転
		/// @param speed 0 ～ 100
		/// @param blocking　true:回転終了後return/false:回転終了を待たずreturn
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool setCounts(int32 degree,int32 speed, bool blocking = false) = 0;

		///
		/// @fn bool setPWM(int32 power)
		/// @brief モーターを指定PWM出力値で回転させる
		/// @param power -100 ～ 100 -で反転
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool setPWM(int32 power) = 0;

		///
		/// @fn bool stop(bool brake = false)
		/// @brief モーターを停止する
		/// @param power true:ブレーキモード/false:フロートモード
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool stop(bool brake = false) = 0;
	};
}