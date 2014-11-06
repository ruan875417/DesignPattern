//------------------------------------------------------------------------
//    Student.h
//------------------------------------------------------------------------
#ifndef STUDENT_H
#define STUDENT_H

#include "Observer.h"
#include<iostream>
using namespace std;

class Student:public Observer{
   private:
      string name;
   public:
      Student(string name);
      string getName();
      void update(Subject* subject);
};

#endif
