// MapStateControl.h
#pragma once
// includeファイル
#include "DistanceMeasure.h"
#include "MapStateDefinition.h"
#include <array>

//定数定義
#define STATE_MAX 16              //走行状態変移の最大数
#define STATE_END 9632.1f         // GOALまでの距離//仮
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
      {{1070.0f, Straight},//(仮)
       {1690.0f, LargeLeftTurn},//(仮)
       {2286.0f, Straight},//(仮)
       {3042.0f, LargeLeftTurn},//(仮)
       {3172.0f, Straight},//(仮)
       {3838.0f, SmallLeftTurn},//(仮)
       {1316.0f, SmallRightTurn},//(仮)
       {5154.0f, Straight},//(仮)
       {5954.0f, LargeRightTurn},//(仮)
       {6864.0f, Straight},//(仮)
       {7500.0f, LargeRightTurn},//(仮)
       {7660.0f, Straight},//(仮)
       {8042.0f, SmallRightTurn},//(仮)
       {9452.0f, SmallLeftTurn},//(仮)
       {9632.0f, Straight},//(仮)
       {9632.1f, Goal}}};//(仮)

  //Rコースの走行手順
  const std::array<DriveState, STATE_MAX> m_stateRight = {
      {{1070.0f, Straight},//(仮)
       {1690.0f, LargeRightTurn},//(仮)
       {2286.0f, Straight},//(仮)
       {3042.0f, LargeRightTurn},//(仮)
       {3172.0f, Straight},//(仮)
       {3838.0f, SmallRightTurn},//(仮)
       {1316.0f, SmallLeftTurn},//(仮)
       {5154.0f, Straight},//(仮)
       {5954.0f, LargeLeftTurn},//(仮)
       {6864.0f, Straight},//(仮)
       {7500.0f, LargeLeftTurn},//(仮)
       {7660.0f, Straight},//(仮)
       {8042.0f, SmallLeftTurn},//(仮)
       {9452.0f, SmallRightTurn},//(仮)
       {9632.0f, Straight},//(仮)
       {9632.1f, Goal}}};//(仮)
};