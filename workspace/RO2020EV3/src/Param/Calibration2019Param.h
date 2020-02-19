#pragma once
#include <RyujiEv3.h>
#include <Drive.h>

struct Calibration2019Param{
    Calibration2019Param* pCalibrationParam;
    int32 tailSpeed;
};  

namespace ParamCalibration2019 {
static Calibration2019Param calibration2019Param{
   &calibration2019Param,
   20
};
}//namespace ParamCalibration2019