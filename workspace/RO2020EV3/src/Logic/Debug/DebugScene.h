#include <ISceneLogic.h>
#include <RyujiEv3.h>
#include <Logger.h>
#include <Detect.h>
#include <Steering.h>
#include <Drive.h>
class DebugScene : public ISceneLogic{
    private:
    public:
        ///
        /// @fn CalibrationScene2019Logic(2019Param* param)
        /// @brief コンストラクタ。パラメータを設定する
        ///
        DebugScene();
        ~DebugScene();
        bool init() override;
        bool run() override;
};