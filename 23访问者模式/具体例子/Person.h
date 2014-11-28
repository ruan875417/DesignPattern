#ifndef PERSON_H
#define PERSON_H
#include<string>
using namespace std;

class Action;
//���󱻷��ʶ����࣬������һ��ͳһ�Ľӿ�Accept
class Person{
   public:
       virtual void accept(Action* visitor)=0;
}; 
//���屻�����࣬ʵ����Accept��������������һ��visitor���ڸú����а��Լ����ݸ�visitor   
class Man:public Person{
   private:
      string sex;
   public:
      Man(string sex);
      string getSex();
      void accept(Action* visitor);
};
//���屻�����࣬ʵ����Accept��������������һ��visitor���ڸú����а��Լ����ݸ�visitor   
class Woman:public Person{
   private:
      string sex;
   public:
      Woman(string sex);
      string getSex();
      void accept(Action* visitor);
};
#endif
