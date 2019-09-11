#pragma once
#include"getUp.h"
#include"infoTail.h"
#include"braker.h"
#include"distanceRunner.h"
#include"lineTracer.h"
#include"tailPositioner.h"

class garageInit{
    public:
        bool run(void);
    private:
        InfoTail m_lineTraseTail1={60,50,false};
        InfoTail m_lineTraseTail2={70,20,false};
        InfoTail m_lineTraseTail3={83,15,true};
        InfoTail m_lineTraseTail4={80,40,true};
        InfoDistanceRun m_safeRun1= {5,12.0f};
        InfoDistanceRun m_safeRun2= {6,7.0f};
        float m_runUpDistance1=-8.0;
        float m_runUpDistance2=-2.0;
        float m_runUpDistance3=-3.0;
        int m_lineReturnTime=1000;
        int m_lineReturnPwm=4;

        float m_firstDistance;
       
        lineTracer m_garageInitlineTracer;
        float m_lineReturnDistance=150.0f;
       
        
};