// MapStateControl.h
#pragma once
// includeファイル
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"
#include <array>

//定数定義
#define STATE_MAX 16              //走行状態変移の最大数
#define STATE_END 150.1f          // GOALまでの距離//仮
#define LEFT_COURSE 0
#define RIGHT_COURSE 1
#define COURSE_MODE LEFT_COURSE   //走行コース設定

//構造体定義
//走行状態管理構造体
struct DriveState {
  float Distance;  //走行状態切り替え規定距離
  MapState State;  //走行状態
};

//クラス定義
//クラス名  :MapStateControl
//機能名    :マップ状態切り替え
//機能概要  :走行距離からマップ状態(直進、右折等)を判断する。

// Lコース　直進、大左折、直進、大左折、直進、小左折、小右折、直進、大右折、直進、大右折、直進、小右折、小左折、直進、ゴール
// Rコース　直進、大右折、直進、大右折、直進、小右折、小左折、直進、大左折、直進、大左折、直進、小左折、小右折、直進、ゴール

class MapStateControl {
 public:
  MapStateControl();          //コンストラクタ
  ~MapStateControl();         //デストラクタ
  //関数名   :drivePosition
  //機能名   :走行位置判断
  //機能概要 :走行距離から走行状態(直線、右カーブ等)を判断する
  //引数     :無し
  //戻り値   :MapState        :走行状態
  MapState drivePosition();

 private:
  int errorCorrection();      //実際の走行状態とマップステータスの誤差検知
  int m_rightNumRotation;     //右モーター回転数
  int m_leftNumRotation;      //左モーター回転数

  //Lコースの走行手順
  const std::array<DriveState, STATE_MAX> m_stateLeft = {
      {{10.0f, Straight},//(仮)
       {20.0f, LargeLeftTurn},//(仮)
       {30.0f, Straight},//(仮)
       {40.0f, LargeLeftTurn},//(仮)
       {50.0f, Straight},//(仮)
       {60.0f, SmallLeftTurn},//(仮)
       {70.0f, SmallRightTurn},//(仮)
       {80.0f, Straight},//(仮)
       {90.0f, LargeRightTurn},//(仮)
       {100.0f, Straight},//(仮)
       {110.0f, LargeRightTurn},//(仮)
       {120.0f, Straight},//(仮)
       {130.0f, SmallRightTurn},//(仮)
       {140.0f, SmallLeftTurn},//(仮)
       {150.0f, Straight},//(仮)
       {150.1f, Goal}}};//(仮)

  //Rコースの走行手順
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{10.0f, Straight},//(仮)
       {20.0f, LargeRightTurn},//(仮)
       {30.0f, Straight},//(仮)
       {40.0f, LargeRightTurn},//(仮)
       {50.0f, Straight},//(仮)
       {60.0f, SmallRightTurn},//(仮)
       {70.0f, SmallLeftTurn},//(仮)
       {80.0f, Straight},//(仮)
       {90.0f, LargeLeftTurn},//(仮)
       {100.0f, Straight},//(仮)
       {110.0f, LargeLeftTurn},//(仮)
       {120.0f, Straight},//(仮)
       {130.0f, SmallLeftTurn},//(仮)
       {140.0f, SmallRightTurn},//(仮)
       {150.0f, Straight},//(仮)
       {150.1f, Goal}}};//(仮)
};