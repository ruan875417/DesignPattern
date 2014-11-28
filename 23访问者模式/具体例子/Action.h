#ifndef ACTION_H
#define ACTION_H

#include "Person.h"
//����������� 
class Action{
   public:
       virtual void getManConclusion(Man* man)=0;
       virtual void getWomanConclusion(Woman* woman)=0;
};
//�����������
class Success:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
};
//�����������
class Failing:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
}; 
//�����������
class Loving:public Action{
   public:
       void getManConclusion(Man* man);
       void getWomanConclusion(Woman* woman);
};
#endif 
