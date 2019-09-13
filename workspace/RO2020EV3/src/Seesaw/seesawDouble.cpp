#include"seesawDouble.h"

bool seesawDouble::run(void){
    seesawRunner i_seesawRunner;
    angleDetector i_angleDetector;
    getUp i_getUp;
    braker i_braker;
    distanceRunner i_distanceRunner;

    
    //if(!i_getUp.run(&m_lineTraceTail,-3.0)){return false;}
    //i_distanceRunner.run(&m_getUpRun);
    if(!i_braker.run()){return false;}
    if(!i_seesawRunner.run(direction::forward)){return false;}
    EV3_LOG("seesawRUnner_forward_finish");
    //if(!i_angleDetector.setTargetValue(m_onSeesawTargetValue)){return false;}
    //if(!i_angleDetector.detect()){return true;}//シーソーシングルに移行
    if(!i_seesawRunner.run(direction::back)){return false;}
    EV3_LOG("seesawRUnner_back_finish");
    if(!i_distanceRunner.run(&m_twiceForwardRun)){return false;}
    if(!i_seesawRunner.run(direction::forward)){return false;}

    return true;
}