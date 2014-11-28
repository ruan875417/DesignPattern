#ifndef ACTION_H
#define ACTION_H

#include "Person.h"
//抽象访问者类 
class Action{
   public:
       virtual void getManConclusion(Man* man)=0;
       virtual void getWomanConclusion(Woman* woman)=0;
};
//具体访问者类
class Success:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
};
//具体访问者类
class Failing:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
}; 
//具体访问者类
class Loving:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
};
#endif 
