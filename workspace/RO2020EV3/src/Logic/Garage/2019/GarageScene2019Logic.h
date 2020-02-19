#pragma once
#include <ISceneLogic.h>
#include "../../../Param/Garage2019Param.h"
#include "CompleteGarage.h"

class GarageScene2019Logic : public ISceneLogic{
    private:
        Garage2019Param* m_param;
        CompleteGarage* m_completeGarage;//コンポジション
    public:
        ///
        /// @fn GarageScene2019Logic(Garage2019Param* param)
        /// @brief コンストラクタ。パラメータを設定する
        ///
        GarageScene2019Logic(Garage2019Param* param);
        ~GarageScene2019Logic();
        bool init() override;
        bool run() override;

};