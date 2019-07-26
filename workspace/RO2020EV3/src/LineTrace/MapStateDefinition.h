// MapStateDefinition.h

//列挙型定義

#pragma once
enum MapState {
  Straight,
  SmallRightTurn,
  SmallLeftTurn,
  LargeRightTurn,
  LargeLeftTurn,
  Goal,
  StateEnd
};