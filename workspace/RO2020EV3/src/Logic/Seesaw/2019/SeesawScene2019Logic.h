#pragma once
#include <ISceneLogic.h>
#include "../../../Param/Seesaw2019Param.h"
class SeesawScene2019Logic : public ISceneLogic{
    private:
        Seesaw2019Param* m_param;
    public:
        ///
        /// @fn SeesawScene2019Logic(Seesaw2019Param* param)
        /// @brief コンストラクタ。パラメータを設定する
        ///
        SeesawScene2019Logic(Seesaw2019Param* param);
        ~SeesawScene2019Logic();
        bool init() override;
        bool run() override;

};