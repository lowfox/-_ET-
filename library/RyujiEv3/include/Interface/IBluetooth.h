///
/// @file IBluetooth.h
/// @brief Bluetoothへのインターフェース
///

#pragma once
#include "../RyujiEv3Forward.h"

namespace RyujiEv3
{
    ///
	/// @brief Bluetooth Interface
	///
    class IBluetooth
    {
    public:

        virtual ~IBluetooth(){}

        ///
		/// @fn uint8 read()
		/// @brief 受信データを1バイト読み込む
		/// @return uint8 読み込んだデータ<br>
        /// 受信データがなければEOF
		///
        virtual uint8 read() = 0;

        ///
		/// @fn bool write(uint8 data)
		/// @brief データを送信する
        /// @param data 送信するデータ
		/// @retval true 成功
        /// @retval false 失敗
		///
        virtual bool write(uint8 data) = 0;

        ///
		/// @fn uint32 writeString(const char* format,...)
		/// @brief 文字列を送信する
        /// @param format フォーマット
		/// @return uint32 書き込めたバイト数
		///
        virtual uint32 writeString(const char* format,...) = 0;
        
        ///
		/// @fn bool isConnected()
		/// @brief Bluetooth接続がされているか調べる
		/// @retval true 接続中
        /// @retval false 未接続 
		///
        virtual bool isConnected() = 0;
    };
}