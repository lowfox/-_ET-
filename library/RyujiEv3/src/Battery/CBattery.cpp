#include "CBattery.h"
#include <ev3api.h>

namespace RyujiEv3
{
    int32 CBattery::get_mV()
    {
        return ev3_battery_voltage_mV();
    }

    int32 CBattery::get_mA()
    {
        return ev3_battery_current_mA();
    }
}