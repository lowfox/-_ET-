#include "Standby.h"
#include <Drive.h>
#include "Run.h"
#include <Logger.h>                               //Takeuchi
#include <Config.h>

//追加変更その他ざっくり by Takeuchi
//ログを吐くように追加
//キャリブレーション時、毎回尻尾位置をリセットするように変更

Standby::Standby() {
  m_tailDegrees.push_back(NomalDeg);

  // L,R,各コースで必要な角度をキャリブレーションする
  switch (LINETRACE_NEXT_SCENE) {
    case SceneID::Lookup:
      m_tailDegrees.push_back(LookUp_1Deg);
      m_tailDegrees.push_back(LookUp_2Deg);
      break;
    case SceneID::Seesaw:
      m_tailDegrees.push_back(Seesaw_1Deg);
      m_tailDegrees.push_back(Seesaw_2Deg);
      m_tailDegrees.push_back(Seesaw_3Deg);
      break;
    default:
      EV3_LOG_ERROR("okapeople");
      break;
  }
}

Standby::~Standby() {}

void Standby::traceMain() {
  auto* Bluetooth = RyujiEv3Engine::GetBluetooth();
  EV3_LOG("SetUp Start\n");                       //Takeuchi
  setup();
  EV3_LOG("SetUp End\n");                         //Takeuchi
#if defined LINETRACE_BLUETOOTH_START
  while (!bluetoothDetection())
    ;
#else
  EV3_LOG("ButtonDetection Start\n");             //Takeuchi
  while (!buttonDetection())
    ;
  EV3_LOG("ButtonDetection End\n");               //Takeuchi
#endif
  EV3_LOG("Run Start\n");                         //Takeuchi
  runStart();
  EV3_LOG("End\n");                               //Takeuchi
}

void Standby::setup() {
  auto* tail = RyujiEv3Engine::GetTailMotor();
  constexpr int32 TAIL_SPEED = 50;	//しっぽモータ回転速度


  //尻尾角度のリセット
  tail->resetCounts();  //尻尾を上にあげきった状態で実行

  int32 prevCount = 0;

  for (const auto& itr : m_tailDegrees) {
    tail->setCounts(itr - prevCount, TAIL_SPEED, true);
   
	Calibration(itr);

    prevCount = itr;
  }

  tail->setCounts(90, 50, true);                   //Takeuchi(尻尾をスタート前の待機ポジションに(角度90°は適当))
}

void Standby::Calibration(int32 degree) {
  auto* touch   = RyujiEv3Engine::GetTouchSensor();
  auto* speaker = RyujiEv3Engine::GetSpeaker();
  auto* lcd     = RyujiEv3Engine::GetLCD();

  TraceColor countColor;

  //黒
  lcd->drawString(0, 0, "GetColor : Black : %d", degree);//Takeuchi(綴り訂正)

  do {
    touch->update();
  } while (!touch->clicked());

  RGB rgb          = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.black = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //白
  lcd->drawString(0, 0, "GetColor : White : %d", degree);

  do {
    touch->update();
  } while (!touch->clicked());
  rgb              = Drive::ColorCalibrate::RGBAverage1Sec();
  countColor.white = (static_cast<float>(rgb.r + rgb.g + rgb.b) / 3.0f);
  speaker->playTone(600, 1);

  //青
  lcd->drawString(0, 0, "GetColor : Blue : %d", degree);//Takeuchi(綴り訂正)
  do {
    touch->update();
  } while (!touch->clicked());
  countColor.blue = Drive::ColorCalibrate::RGBAverage1Sec();
  speaker->playTone(600, 1);


  EV3_LOG("degree = %d\nAdd Trace Color black = %f\nAdd Trace Color blue = R%dG%dB%d\nAdd Trace Color white = %f\n", degree, countColor.black, countColor.blue.r, countColor.blue.g, countColor.blue.b,countColor.white);//Takeuchi
  Drive::ColorCalibrate::AddTraceColor(degree, countColor);
}

bool Standby::bluetoothDetection() {
  auto* bluetooth = RyujiEv3Engine::GetBluetooth();

  if (!bluetooth->isConnected()) {
    return false;
  }

  // スタート識別信号
  constexpr uint8 START_SIGNAL = '1';

  // スタート信号受信まで待機
  while (bluetooth->read() != START_SIGNAL)
    ;

  return true;
}

bool Standby::buttonDetection() {
  auto* touch = RyujiEv3Engine::GetTouchSensor();
  auto* lcd = RyujiEv3Engine::GetLCD();//Takeuchi
  lcd->drawString(0, 0, "Plese Push Botton");//Takeuchi
  // Button、押されたらtrueをリターン
  do {
    touch->update();
  } while (!touch->clicked());

  return true;
}

void Standby::runStart() {
  Run start;
  start.driveStart();
}
