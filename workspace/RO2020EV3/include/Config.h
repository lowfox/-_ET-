///
/// @file Config.h
/// @brief ET���{�R���v���W�F�N�g�̐ݒ�
///
#pragma once
#include <RyujiEv3.h>
#include <vector>
#include "../src/Param/Seesaw2019Param.h"
#include "../src/Param/Garage2019Param.h"

//コースの選択
#define COURSE Course2019Left

//TODO : COUSEの設定、実行するシーンの設定、パラメータの設定
//実行するシーンの設定
constexpr int FIRST_SCENE = 0;
constexpr int SECOND_SCENE = 1;
constexpr int THIRD_SCENE = 2;
constexpr int FORTH_SCENE = 3;
constexpr int FIFTH_SCENE = 4;


constexpr int RUNSCENES[] = {FIRST_SCENE, SECOND_SCENE};

//パラメータの選択
#define GARAGE2019PARAM ParamGarage2019::garage2020Param.pGrageParam
#define SEESAW2019PARAM ParamSeesaw2019::seesaw2021Param.pSeesawParam


/// EV3�̊e�Z���T�[,���[�^�[�̐ڑ��|�[�g
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