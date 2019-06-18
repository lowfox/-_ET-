///
/// @file IBattery.h
/// @brief バッテリーへのインターフェース
///
#pragma once

#include "../RyujiEv3Forward.h"

namespace RyujiEv3 {
///
/// @brief Battery Interface
///
class IBattery {
 public:
  virtual ~IBattery() {}

  ///
  /// @fn int32 get_mV()
  /// @brief バッテリの電圧[mV]を取得する
  /// @return int32 現在のバッテリの電圧[mV]
  ///
  virtual int32 get_mV() = 0;

  ///
  /// @fn int32 get_mA()
  /// @brief バッテリの電流[mA]を取得する
  /// @return int32 現在のバッテリの電流[mA]
  ///
  virtual int32 get_mA() = 0;
};
}  // namespace RyujiEv3
