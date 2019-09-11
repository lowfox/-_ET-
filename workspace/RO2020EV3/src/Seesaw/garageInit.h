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
        InfoTail m_lineTraseTail1={60,30,false};
        InfoTail m_lineTraseTail2={70,20,false};
        InfoTail m_lineTraseTail3={90,10,true};
        InfoTail m_lineTraseTail4={80,40,true};
        InfoDistanceRun m_safeRun1= {5,14.0f};
         InfoDistanceRun m_safeRun2= {6,7.0f};
        float m_runUpDistance1=-6.0;
        float m_runUpDistance2=-3.0;
        float m_runUpDistance3=-1.2;
        int m_lineReturnTime=1000;
        int m_lineReturnPwm=4;

        float m_firstDistance;
       
        lineTracer m_garageInitlineTracer;
        float m_lineReturnDistance=150.0f;
       
        
};