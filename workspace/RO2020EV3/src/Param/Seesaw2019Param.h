#pragma once
struct Seesaw2019Param{
   Seesaw2019Param* pSeesawParam;
   int sami;
   int distance;
   int ii;
 };  
namespace ParamSeesaw2019 {
static Seesaw2019Param seesaw2019Param{
   &seesaw2019Param,
    20,  // sami
    10,  // distance
    2    // ii
};

static Seesaw2019Param seesaw2020Param{
   &seesaw2020Param,
    4,  // sami
    5,  // distance
    6   // ii
};

static Seesaw2019Param seesaw2021Param{
   &seesaw2021Param,//ポインタを入れればwarningの、define but not usedがなくなる
    4,  // sami
    5,  // distance
    6   // ii
};


}  // namespace ParamSeesaw2019
