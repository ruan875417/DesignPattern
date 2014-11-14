#ifndef CSTATE_H
#define CSTATE_H

#include "CWork.h"
#include <iostream>
using namespace std;
class CWork; 
class CState{
    public:
       CState(){};
       virtual void work(CWork* work)=0;
};
//晚上时间  
class EveningState:public CState{
    public:
       void work(CWork* work);
};
//傍晚时间  
class TowardEveningState:public CState{
    public:
       void work(CWork* work);
};
//下午时间  
class AfternoonState:public CState{
    public:
       void work(CWork* work);
};
//中午时间  
class NoonState:public CState{
    public:
       void work(CWork* work);
};
//上午工作  
class ForenoonState:public CState{
    public:
       void work(CWork* work);
};
#endif
