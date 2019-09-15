#include "RyujiEv3Engine.h"
#include "Battery/CBattery.h"
#include "Bluetooth/CBluetooth.h"
#include "ColorSensor/CColorSensor.h"
#include "GyroSensor/CGyroSensor.h"
#include "LCD/CLCD.h"
#include "LED/CLED.h"
#include "Motor/Cmotor.h"
#include "SonarSensor/CSonarSensor.h"
#include "Speaker/CSpeaker.h"
#include "TouchSensor/CTouchSensor.h"
#include "ev3api.h"

namespace RyujiEv3 {
RyujiEv3Engine* RyujiEv3Engine::m_engine = nullptr;

RyujiEv3Engine::RyujiEv3Engine(PortData initData) {
  if (isActive()) {
    return;
  }

  // dynamic_cast使えないの
  auto* pbattery     = new CBattery;
  auto* plcd         = new CLCD;
  auto* pled         = new CLED;
  auto* pspeaker     = new CSpeaker;
  auto* pcolorSensor = new CColorSensor;
  auto* psonarSensor = new CSonarSensor;
  auto* pgyroSensor  = new CGyroSensor;
  auto* ptouchSensor = new CTouchSensor;

  auto* pleftMotor  = new CMotor;
  auto* prightMotor = new CMotor;
  auto* ptailMotor  = new CMotor;

  auto* pbluetooth = new CBluetooth;

  if (!pcolorSensor->init(initData.colorSensor)) {
    return;
  }
  if (!psonarSensor->init(initData.sonarSensor)) {
    return;
  }
  if (!pgyroSensor->init(initData.gyroSensor)) {
    return;
  }
  if (!ptouchSensor->init(initData.touchSensor)) {
    return;
  }

  if (!pleftMotor->init(initData.leftMotor)) {
    return;
  }
  if (!prightMotor->init(initData.rightMotor)) {
    return;
  }
  if (!ptailMotor->init(initData.tailMotor)) {
    return;
  }
  if (!pbluetooth->init()) {
    return;
  }

  m_battery     = pbattery;
  m_lcd         = plcd;
  m_led         = pled;
  m_speaker     = pspeaker;
  m_colorSensor = pcolorSensor;
  m_sonarSensor = psonarSensor;
  m_gyroSensor  = pgyroSensor;
  m_touchSensor = ptouchSensor;

  m_leftMotor  = pleftMotor;
  m_rightMotor = prightMotor;
  m_tailMotor  = ptailMotor;

  m_bluetooth = pbluetooth;

  m_engine = this;
}

void RyujiEv3Engine::Relese() {
  if (!isActive()) {
    return;
  }

  delete m_battery;
  delete m_led;
  delete m_lcd;
  delete m_speaker;
  delete m_leftMotor;
  delete m_rightMotor;
  delete m_tailMotor;
  delete m_colorSensor;
  delete m_gyroSensor;
  delete m_sonarSensor;
  delete m_touchSensor;
  delete m_bluetooth;
  m_engine = nullptr;
}

RyujiEv3Engine::~RyujiEv3Engine() { Relese(); }
}  // namespace RyujiEv3