///
/// @file Config.h
/// @brief ETロボコンプロジェクトの設定
///
#pragma once
#include <RyujiEv3.h>
#include <SceneManager.h>

/// 最初に起動するシーン
constexpr SceneID START_SCENE_ID = SceneID::LineTrace;

/// ライントレース班の次に呼ばれるシーン
constexpr SceneID LINETRACE_NEXT_SCENE = SceneID::Seesaw;

/// EV3の各センサー,モーターの接続ポート
constexpr PortData ROBOCON_PORT = {
    // ColorSensor
    SensorPort::PORT_3,

    // TouchSensor
    SensorPort::PORT_1,

    // GyroSensor
    SensorPort::PORT_4,

    // SonarSensor
    SensorPort::PORT_2,

    // LeftMotor
    MotorPort::PORT_C,

    // RightMotor
    MotorPort::PORT_B,

    // TailMotor
    MotorPort::PORT_A};