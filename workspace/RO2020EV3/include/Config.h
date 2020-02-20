///
/// @file Config.h
/// @brief ET���{�R���v���W�F�N�g�̐ݒ�
///
#pragma once
#include <RyujiEv3.h>
#include <vector>
//コース
#include "src/Course/2019/Course2019Left.h"
#include "src/Course/2019/Course2019Right.h"
#include "src/Course/DebugCourse.h"
//パラメータ
#include "../src/Param/Seesaw2019Param.h"
#include "../src/Param/Garage2019Param.h"
#include "../src/Param/Calibration2019Param.h"

//コースの選択
#define COURSE DebugCourse

//TODO : COUSEの設定、実行するシーンの設定、パラメータの設定
//実行するシーンの設定
constexpr uint8 FIRST_SCENE = 0;
constexpr uint8 SECOND_SCENE = 1;
constexpr uint8 THIRD_SCENE = 2;
constexpr uint8 FORTH_SCENE = 3;
constexpr uint8 FIFTH_SCENE = 4;
constexpr uint8 END = 255;

constexpr uint8 RUNSCENES[] = {FIRST_SCENE,SECOND_SCENE,END};

//パラメータの選択
#define GARAGE2019PARAM ParamGarage2019::garage2020Param.pGrageParam
#define SEESAW2019PARAM ParamSeesaw2019::seesaw2021Param.pSeesawParam
#define CALIBRATION2019PARAM ParamCalibration2019::calibration2019Param.pCalibrationParam

//キャリブレーション角度設定
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