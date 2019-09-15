///
/// @file RyujiEv3Forward.h
/// @brief 前方宣言
///
#pragma once
#include <memory>
#include "RyujiEv3TypeAlias.h"

namespace RyujiEv3 {
class RyujiEv3Engine;

// Interface
class ILED;
class ILCD;
class IBattery;
class ISpeaker;
class IColorSensor;
class ISonarSensor;
class IGyroSensor;
class ITouchSensor;
class IMotor;
class IBluetooth;

enum class SensorPort;
enum class MotorPort;
struct PortData;
}  // namespace RyujiEv3