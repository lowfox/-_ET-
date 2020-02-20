#pragma once
#include <RyujiEv3.h>
#include <Drive.h>
struct AreaEndTrriger{
   ReadColor detectLineColor;
   float distance;
};
struct LineTraceConfig{
   TraceColor traceColor;
   int32 speed;
   PID pid;
};
struct Garage2019Param{
   Garage2019Param* pGrageParam;
   LineTraceConfig area1Config;
   LineTraceConfig area2Config;
   LineTraceConfig area3Config;
   ReadColor area1CurrentColor;
   ReadColor area2CurrentColor;
   ReadColor area3CurrentColor;
   AreaEndTrriger area1EndTrriger;   
   AreaEndTrriger area2EndTrriger;   
   AreaEndTrriger area3EndTrriger;   
   int32 traceAngle;
};  

namespace ParamGarage2019 {
static Garage2019Param garage2019Param{
   &garage2019Param,
   {//area1congig
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      30,                  //speed
      {0.24f,0.0f,0.2f}
   },
   {//area2config 青ライントレース
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      30,
      {0.24f,0.0f,0.2f}
   },
   {
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      30,
      {0.24f,0.0f,0.2f}
   },
   ReadColor::BLACK,//area1currentcolor
   ReadColor::BLUE,
   ReadColor::BLACK,
   {//area1Trriger
      ReadColor::BLUE,
      0
   },
   {
      ReadColor::BLACK,
      0
   },
   {
      ReadColor::BLACK,
      100
   }
};
static Garage2019Param garage2020Param{
   &garage2020Param,
   {//area1congig
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      5,                  //speed
      {0.24f,0.0f,0.2f}
   },
   {//area2config 青ライントレース
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      5,
      {0.24f,0.0f,0.2f}
   },
   {
      {5.6f,123.0f,{11,45,122}},   //tracecolor
      5,
      {0.24f,0.0f,0.2f}
   },
   ReadColor::BLACK,//area1currentColor
   ReadColor::BLUE,
   ReadColor::BLACK,
   {
      ReadColor::BLUE,
      0.0f
   },
   {
      ReadColor::BLACK,
      0.0f
   },
   {
      ReadColor::NONE,
      100.0f
   },
   83

};
}  // namespace ParamGarage2019