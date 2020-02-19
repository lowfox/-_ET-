#pragma once
#include <RyujiEv3.h>
#include "../../../Param/Garage2019Param.h"
#include "GarageLineTrace.h"
#include "RecognizeCurrentRocation.h"
#include <RyujiEv3.h>
class CompleteGarage{
    private:
        Garage2019Param* m_param;
        GarageLineTrace* m_gLineTrace;//集約
        RecognizeCurrentRocation* m_recognizeCurrentRocation;//集約
        //青ラインまで移動
        bool moveBlueLine();
        //黒ラインまで移動
        bool moveBlackLine();
        //ガレージまで移動
        bool moveGarage();
        bool endDelete();
   public:
        CompleteGarage(Garage2019Param* param);
        ~CompleteGarage();
        bool run();

};