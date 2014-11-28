#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Action;
//抽象被访问对象类，定义了一个统一的接口Accept
class Person{
   public:
       virtual void accept(Action* visitor)=0;
}; 
//具体被访问类，实现了Accept（）函数，接收一个visitor，在该函数中把自己传递给visitor   
class Man:public Person{
   private:
      string sex;
   public:
      Man(string sex);
      string getSex();
      void accept(Action* visitor);
};
//具体被访问类，实现了Accept（）函数，接收一个visitor，在该函数中把自己传递给visitor   
class Woman:public Person{
   private:
      string sex;
   public:
      Woman(string sex);
      string getSex();
      void accept(Action* visitor);
};
#endif
