///
/// @file RyujiEv3Engine.h
/// @brief りゅうじのいーぶいすりー
///
#pragma once
#include "RyujiEv3Forward.h"

namespace RyujiEv3
{
	///
	/// @brief りゅうじのいーぶいすりー
	///
	class RyujiEv3Engine
	{
	private:

		static RyujiEv3Engine* m_engine;

		IBluetooth* m_bluetooth;

		IBattery* m_battery;

		ILCD* m_lcd;

		ILED* m_led;

		ISpeaker* m_speaker;

		IMotor* m_leftMotor;

		IMotor* m_rightMotor;

		IMotor* m_tailMotor;

		IColorSensor* m_colorSensor;

		IGyroSensor* m_gyroSensor;

		ITouchSensor* m_touchSensor;

		ISonarSensor* m_sonarSensor;

	public:

		///
		/// @brief コンストラクタ
		/// @param initData 物理的に接続している各パーツのポート番号
		///
		RyujiEv3Engine(PortData initData);

		~RyujiEv3Engine();

		///
		/// @fn void Relese()
		/// @brief エンジンを解放する
		///
		void Relese();

		///
		/// @fn bool isActive()
		/// @brief エンジンの稼働状態を調べる
		/// @details 稼働していない場合はエンジンの使用はできない
		/// @retval true エンジン稼働中
		/// @retval false エンジンが稼働していない
		///
		static bool isActive()
		{
			return m_engine;
		}

		///
		/// @fn IBluetooth* GetBluetooth()
		/// @brief Bluetoothへのインターフェースを取得する
		/// @return IBluetooth* Bluetoothへのインターフェース
		///
		static IBluetooth* GetBluetooth()
		{
			return m_engine->m_bluetooth;
		}

		///
		/// @fn IBattery* GetBattery()
		/// @brief Batteryへのインターフェースを取得する
		/// @return IBattery* Batteryへのインターフェース
		///
		static IBattery* GetBattery()
		{
			return m_engine->m_battery;
		}

		///
		/// @fn ILCD* GetLCD()
		/// @brief LCDへのインターフェースを取得する
		/// @return ILCD* LCDへのインターフェース
		///
		static ILCD* GetLCD()
		{
			return m_engine->m_lcd;
		}

		///
		/// @fn ILED* GetLED()
		/// @brief LEDへのインターフェースを取得する
		/// @return ILED* LEDへのインターフェース
		///
		static ILED* GetLED()
		{
			return m_engine->m_led;
		}

		///
		/// @fn ISpeaker* GetSpeaker()
		/// @brief スピーカーへのインターフェースを取得する
		/// @return ISpeaker* スピーカーへのインターフェース
		///
		static ISpeaker* GetSpeaker()
		{
			return m_engine->m_speaker;
		}

		///
		/// @fn IMotor* GetLeftMotor()
		/// @brief 左モーターへのインターフェースを取得する
		/// @return IMotor* 左モーターへのインターフェース
		///
		static IMotor* GetLeftMotor()
		{
			return m_engine->m_leftMotor;
		}

		///
		/// @fn IMotor* GetRightMotor()
		/// @brief 右モーターへのインターフェースを取得する
		/// @return IMotor* 右モーターへのインターフェース
		///
		static IMotor* GetRightMotor()
		{
			return m_engine->m_rightMotor;
		}

		///
		/// @fn IMotor* GetTailMotor()
		/// @brief しっぽモーターへのインターフェースを取得する
		/// @return IMotor* しっぽモーターへのインターフェース
		///
		static IMotor* GetTailMotor()
		{
			return m_engine->m_tailMotor;
		}

		///
		/// @fn IColorSensor* GetColorSensor()
		/// @brief カラーセンサーへのインターフェースを取得する
		/// @return IColorSensor* カラーセンサーへのインターフェース
		///
		static IColorSensor* GetColorSensor()
		{
			return m_engine->m_colorSensor;
		}

		///
		/// @fn IGyroSensor* GetGyroSensor()
		/// @brief ジャイロセンサーへのインターフェースを取得する
		/// @return IGyroSensor* ジャイロセンサーへのインターフェース
		///
		static IGyroSensor* GetGyroSensor()
		{
			return m_engine->m_gyroSensor;
		}

		///
		/// @fn ITouchSensor* GetTouchSensor()
		/// @brief タッチセンサーへのインターフェースを取得する
		/// @return ITouchSensor* タッチセンサーへのインターフェース
		///
		static ITouchSensor* GetTouchSensor()
		{
			return m_engine->m_touchSensor;
		}

		///
		/// @fn ISonarSensor* GetSonarSensor()
		/// @brief 超音波センサーへのインターフェースを取得する
		/// @return ISonarSensor* 超音波センサーへのインターフェース
		///
		static ISonarSensor* GetSonarSensor()
		{
			return m_engine->m_sonarSensor;
		}
	};
}