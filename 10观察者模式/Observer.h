//--------------------------------------------------------------------------------
//     Observer.h             π€≤Ï’ﬂ
//--------------------------------------------------------------------------------
#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"
using namespace std;

class Subject;
class Observer{
   public:
      Observer(){}
      ~Observer(){}
      virtual void update(Subject* subject) = 0;
};

#endif
