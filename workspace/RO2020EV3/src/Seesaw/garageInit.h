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
        InfoTail m_lineTraseTail4={80,15,true};
        InfoDistanceRun m_safeRun1= {5,12.0f};
        InfoDistanceRun m_safeRun2= {6,7.0f};
        float m_runUpDistance1=-6.5;
        float m_runUpDistance3=-1.8;
        int m_lineReturnTime=800;
        int m_lineReturnPwm=4;

        float m_firstDistance;
       
        lineTracer m_garageInitlineTracer;
        float m_lineReturnDistance=80.0f;

        int16 m_garageInitAngle=80;
       
        
};