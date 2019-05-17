///
/// @file ILED.h
/// @brief LEDへのインターフェース
///
#pragma once

namespace RyujiEv3
{
	/// @enum LED_Color
    /// @brief LEDの色
	enum class LED_Color
	{
		/// 消灯
		OFF    = 0,

		/// 赤
		RED    = 1 << 0,

		/// 緑
		GREEN  = 1 << 1,

		/// オレンジ
		ORANGE = RED | GREEN
	};

	///
	/// @brief LED Interface
	///
	class ILED
	{
	public:

		virtual ~ILED() {}

		///
		/// @fn bool setColor(LED_Color color)
		/// @brief LEDの色を指定する
		/// @param color 光らせるLEDの色
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool setColor(LED_Color color) = 0;

		
		///
		/// @fn LED_Color getColor()
		/// @brief 現在のLEDの色を取得する
		/// @return LED_Color 現在のLEDの色
		///
		virtual LED_Color getColor() = 0;
	};
}