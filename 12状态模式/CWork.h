#ifndef CWORK_H
#define CWORK_H

#include "CState.h" 
class CState;
class CWork{
    private:
       CState* curstate;
       double curtime;
    public:
       CWork(){};
       void setTime(double hour);
       double getTime();
       void setState(CState* state);
       void work();
};

#endif
