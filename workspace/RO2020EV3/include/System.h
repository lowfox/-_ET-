///
/// @file System.h
/// @brief システム関数
///
#pragma once
#include <RyujiEv3.h>

namespace System {
///
/// @fn bool Init(const PortData& port)
/// @brief ライブラリの初期化処理
/// @param port センサ、モーターの接続されているポート情報
/// @retval true 成功
/// @retval false 失敗
///
bool Init(const PortData& port);

///
/// @fn void Exit()
/// @brief ライブラリの終了処理
///
void Exit();
}  // namespace System