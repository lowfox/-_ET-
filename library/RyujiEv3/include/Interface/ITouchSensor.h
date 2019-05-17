///
/// @file ITouchSensor.h
/// @brief タッチセンサーへのインターフェース
///
#pragma once
#include "../RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief TouchSensor Interface
	///
	class ITouchSensor
	{
	public:

		virtual ~ITouchSensor(){}
		
		///
		/// @fn bool click()
		/// @brief ボタンさ押し込まれた
		/// @retval true 押しこまれた
		/// @retval false おしこまれていない
		///
		virtual bool click() = 0;

		///
		/// @fn bool clicked()
		/// @brief ボタンが離された
		/// @retval true 離された
		/// @retval false 離されていない
		///
		virtual bool clicked() = 0;

		///
		/// @fn bool pressing()
		/// @brief ボタンが押されているか
		/// @retval true 押されている
		/// @retval false 押されていない
		///
		virtual bool pressing() = 0;

		///
		/// @fn bool update()
		/// @brief 更新処理 
		/// @retval true 成功
		/// @retval false 失敗
		///
		virtual bool update() = 0;
	};
}
