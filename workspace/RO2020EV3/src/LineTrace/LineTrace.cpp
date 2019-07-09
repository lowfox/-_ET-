// LineTrace.cpp

// includeファイル
#include <Drive.h>
#include "LineTrace.h"

LineTrace::LineTrace()
{
}

LineTrace::~LineTrace()
{
}

int LineTrace::lineTraceDrive(MapState runState)
{
  // 戻り値は、PIDのセットに成功したかどうか。GetPID関数で現在セットされてるPID分かるので、セット後にそれ呼べば反映されてるかわかる。

  //PID値初期化
  //直線
  m_straightPID.kp    = hoge;
  m_straightPID.ki    = hoge;
  m_straightPID.kd    = hoge;
  //右小回り
  m_smallRightTurn.kp = hoge;
  m_smallRightTurn.ki = hoge;
  m_smallRightTurn.kd = hoge;
  //右大回り
  m_largeRightTurn.kp = hoge;
  m_largeRightTurn.ki = hoge;
  m_largeRightTurn.kd = hoge;
  //左小回り
  m_smallLeftTurn.kp  = hoge;
  m_smallLeftTurn.ki  = hoge;
  m_smallLeftTurn.kd  = hoge;
  //左大回り
  m_largeLeftTurn.kp  = hoge;
  m_largeLeftTurn.ki  = hoge;
  m_largeLeftTurn.kd  = hoge;


  //runStateによってセットするPID値を変更する
  switch (runState) {
    case Straight:
      Drive::LineTrace::SetPID(m_straightPID);
      break;

    case SmallRightTurn:
      Drive::LineTrace::SetPID(m_smallRightTurn);
      break;

    case SmallLeftTurn:
      Drive::LineTrace::SetPID(m_smallLeftTurn);
      break;

    case LargeRightTurn:
      Drive::LineTrace::SetPID(m_largeRightTurn);
      break;

    case LargeLeftTurn:
      Drive::LineTrace::SetPID(m_largeLeftTurn);
      break;

    //走行状態一覧に当てはまらなければエラーで-1を返す
    default:
      return -1;
      break;
  }

  //正常に値がセットされたか確認
  PID check;
  //現在セットされているPID値を取得
  check = Drive::LineTrace::GetPID();
  //本来セットされているはずの値と一致したら正常終了
  switch (runState) {
    case Straight:
      if (check.kp == m_straightPID.kp && check.ki == m_straightPID.ki &&
          check.kd == m_straightPID.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case SmallRightTurn:
      if (check.kp == m_smallRightTurn.kp && check.ki == m_smallRightTurn.ki &&
          check.kd == m_smallRightTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case SmallLeftTurn:
      if (check.kp == m_smallLeftTurn.kp && check.ki == m_smallLeftTurn.ki &&
          check.kd == m_smallLeftTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case LargeRightTurn:
      if (check.kp == m_largeRightTurn.kp && check.ki == m_largeRightTurn.ki &&
          check.kd == m_largeRightTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    case LargeLeftTurn:
      if (check.kp == m_largeLeftTurn.kp && check.ki == m_largeLeftTurn.ki &&
          check.kd == m_largeLeftTurn.kd) {
        return 0;
      } else {
        return -1;
      }
      break;

    default:
      return -1;
      break;
  }

}