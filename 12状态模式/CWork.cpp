#include "CWork.h"

void CWork::setTime(double hour){
     curtime=hour; 
} 
double CWork::getTime(){
     return curtime;
}
void CWork::setState(CState* state){
     curstate=state;
}
void CWork::work(){
     curstate->work(this);
}
