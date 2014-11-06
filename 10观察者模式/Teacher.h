//--------------------------------------------------------------------------
//     Teacher.h
//--------------------------------------------------------------------------
#ifndef TEACHER_H
#define TEACHER_H

#include "Subject.h"
#include<list>
#include<iterator>
using namespace std;

class Teacher:public Subject{
   private:
      list <Observer*> observerlist;
      string content;
   public:
      Teacher();
      void attach(Observer* observer);//注册观察者  
      void detach(Observer* observer);//注销观察者  
      void notify();//若状态变化，则遍历观察者，逐个通知更新  
      void setContent(string str);
      string getContent();
};

#endif
