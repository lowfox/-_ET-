///
/// @file ISpeaker.h
/// @brief スピーカーへのインターフェース
///
#pragma once
#include "../RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief Speaker Interface
	///
	class ISpeaker
	{
	public:

		virtual ~ISpeaker() {}

		///
		/// @fn bool setVolume(uint8 volume)
		/// @brief 音量を設定する
		/// @param volume 音量(0～255)
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool setVolume(uint8 volume) = 0;

		///
		/// @fn uint8 getVolume()
		/// @brief 現在の音量を取得する
		/// @return uint8 現在の音量
		///
		virtual uint8 getVolume() = 0;

		///
		/// @fn bool playFile(const char* path, int32 duration)
		/// @brief wavファイルを再生する
		/// @param path wavファイルへのパス
		/// @param duration 再生時間[msec] -1で最後まで再生
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool playFile(const char* path, int32 duration) = 0;

		///
		/// @fn bool playTone(uint16 frequency, int32 duration)
		/// @brief 指定した周波数の音を再生する
		/// @param fraquency 周波数[Hz]
		/// @param duration 再生時間[msec] -1で停止
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool playTone(uint16 frequency, int32 duration) = 0;

		///
		/// @fn bool stop()
		/// @brief 再生している音を停止する
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool stop() = 0;
	};
}