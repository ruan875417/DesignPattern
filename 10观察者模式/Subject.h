//-------------------------------------------------------------------
//   Subject.h        被观察对象
//-------------------------------------------------------------------

#ifndef SUBJECT_H
#define SUBJECT_H

#include<string>
#include "Observer.h"
using namespace std;

class Observer;
class Subject{
   public:
      Subject(){}
      ~Subject(){}
      virtual void attach(Observer* observer) = 0;
      virtual void detach(Observer* observer) = 0;
      virtual void notify() = 0;
      virtual void setContent(string str) = 0;
      virtual string getContent() = 0;
};

#endif
