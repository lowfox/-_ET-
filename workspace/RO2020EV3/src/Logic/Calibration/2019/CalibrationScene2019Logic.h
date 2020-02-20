#pragma once
#include <ISceneLogic.h>
#include <RyujiEv3.h>
#include <vector>
#include <Logger.h>
#include "../../../Param/Calibration2019Param.h"
#include <Drive.h>
class CalibrationScene2019Logic : public ISceneLogic{
    private:
        Calibration2019Param* m_param; 
        std::vector<int32> m_tailDegree={83};
        TraceColor countColor;
    public:
        ///
        /// @fn CalibrationScene2019Logic(2019Param* param)
        /// @brief コンストラクタ。パラメータを設定する
        ///
        CalibrationScene2019Logic(Calibration2019Param* param);
        ~CalibrationScene2019Logic();
        bool init() override;
        bool run() override;

};