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
      void attach(Observer* observer);//ע��۲���  
      void detach(Observer* observer);//ע���۲���  
      void notify();//��״̬�仯��������۲��ߣ����֪ͨ����  
      void setContent(string str);
      string getContent();
};

#endif
