#include "Interface/IBattery.h"

namespace RyujiEv3 {
class CBattery : public IBattery {
 public:
  int32 get_mV() override;

  int32 get_mA() override;
};
}  // namespace RyujiEv3