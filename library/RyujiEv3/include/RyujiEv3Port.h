/// 
/// @file RyujiEv3Port.h
///
/// @brief EV3ポート
///
#pragma once
#include "RyujiEv3Forward.h"

namespace RyujiEv3
{
	// センサーポート
	enum class SensorPort
	{
		PORT_1,
		PORT_2,
		PORT_3,
		PORT_4
	};

	// モーターポート
	enum class MotorPort
	{
		PORT_A,
		PORT_B,
		PORT_C,
		PORT_D
	};

	// センサーの種類
	enum class SensorType
	{
		None  = 0,
		Sonar = 1,
		Gyro  = 2,
		Touch = 3,
		Color = 4,
	};

	// モータータイプ
	enum class MotorType
	{
		None    = 0,
		Medium  = 1,
		Large   = 2
	};

	// ETロボコン用ポートデータ
	struct PortData
	{
		SensorPort colorSensor;
		SensorPort touchSensor;
		SensorPort gyroSensor;
		SensorPort sonarSensor;

		MotorPort leftMotor;
		MotorPort rightMotor;
		MotorPort tailMotor;
	};
}