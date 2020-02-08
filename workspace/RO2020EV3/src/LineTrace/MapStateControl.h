// MapStateControl.h
#pragma once
// includeファイル
#include <array>
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"

//定数定義
#define STATE_MAX 16       //走行状態変移の最大数
#define STATE_END 9372.1f  // GOALまでの距離//仮
#define LEFT_COURSE 0
#define RIGHT_COURSE 1
#define COURSE_MODE RIGHT_COURSE  //走行コース設定

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
  MapStateControl();   //コンストラクタ
  ~MapStateControl();  //デストラクタ
  //関数名   :drivePosition
  //機能名   :走行位置判断
  //機能概要 :走行距離から走行状態(直線、右カーブ等)を判断する
  //引数     :無し
  //戻り値   :int        :走行状態
  int drivePosition();
  void drivePositionReset();

 private:
  int errorCorrection();  //実際の走行状態とマップステータスの誤差検知
  int m_rightNumRotation;  //右モーター回転数
  int m_leftNumRotation;   //左モーター回転数
  int nowState = 0;        //現在の走行状態

  // Lコースの走行手順
  const std::array<DriveState, STATE_MAX> m_stateLeft = {
      {{620.0f + 80 - 5, Straight},
       {1240.0f + 80, LargeLeftTurn},
       {1836.0f + 80, Straight},
       {2592.0f + 80, LargeLeftTurn},
       {2722.0f + 80, Straight},
       {3388.0f + 80, SmallLeftTurn},
       {4704.0f + 80, SmallRightTurn},
       {4894.0f + 80, Straight},
       {5694.0f + 80, LargeRightTurn},
       {6604.0f + 80, Straight},
       {7240.0f + 80, LargeRightTurn},
       {7400.0f + 80, Straight},
       {7782.0f + 80 - 50, SmallRightTurn},
       {9192.0f + 80, SmallLeftTurn},
       {9372.0f + 80, Straight},
       {9372.1f + 80, Goal}}};

  // Rコースの走行手順
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{620.0f + 80 - 5, Straight},
       {1240.0f + 80, LargeRightTurn},
       {1836.0f + 80, Straight},
       {2592.0f + 80, LargeRightTurn},
       {2722.0f + 80, Straight},
       {3388.0f + 80, SmallRightTurn},
       {4704.0f + 80, SmallLeftTurn},
       {4894.0f + 80, Straight},
       {5694.0f + 80, LargeLeftTurn},
       {6604.0f + 80, Straight},
       {7240.0f + 80, LargeLeftTurn},
       {7400.0f + 80, Straight},
       {7782.0f + 80 - 50, SmallLeftTurn},
       {9192.0f + 80, SmallRightTurn},
       {9372.0f + 80, Straight},
       {9372.1f + 80, Goal}}};
};