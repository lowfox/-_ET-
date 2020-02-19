#pragma once
#include "DetectLineColor.h"
#include "DetectMireage.h"
#include <Detect.h>
#include <RyujiEv3.h>
#include <Steering.h>
#include "../../../Param/Garage2019Param.h"
class RecognizeCurrentRocation{
    private:
        Garage2019Param* m_param;
        int m_currentArea = 1;
        DetectLineColor* m_detectLineColor;//集約
        DetectMireage* m_detectMireage;//集約
        bool endDelete();
    public:
        RecognizeCurrentRocation(Garage2019Param* param);
        ~RecognizeCurrentRocation();
        int getCurrentRocation();
};