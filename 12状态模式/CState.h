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
//����ʱ��  
class EveningState:public CState{
    public:
       void work(CWork* work);
};
//����ʱ��  
class TowardEveningState:public CState{
    public:
       void work(CWork* work);
};
//����ʱ��  
class AfternoonState:public CState{
    public:
       void work(CWork* work);
};
//����ʱ��  
class NoonState:public CState{
    public:
       void work(CWork* work);
};
//���繤��  
class ForenoonState:public CState{
    public:
       void work(CWork* work);
};
#endif
