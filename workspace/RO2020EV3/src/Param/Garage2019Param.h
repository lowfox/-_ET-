#pragma once

struct Garage2019Param{
   Garage2019Param* pGrageParam;
   int sami;
   int distance;
   int ii;
 };  

namespace ParamGarage2019 {
static Garage2019Param garage2019Param{
   &garage2019Param,
    20,  // sami
    10,  // distance
    2    // ii
};

static Garage2019Param garage2020Param{
   &garage2020Param,
    4,  // sami
    5,  // distance
    6   // ii
};

}  // namespace ParamGarage2019