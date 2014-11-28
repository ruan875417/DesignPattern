#ifndef ELEMENT_H
#define ELEMENT_H
#include<string>
using namespace std;
class Visitor;
//���󱻷��ʶ����࣬������һ��ͳһ�Ľӿ�Accept
class Element{
    public:
       virtual void accept(Visitor* visitor)=0;
};
//���屻�����࣬ʵ����Accept��������������һ��visitor���ڸú����а��Լ����ݸ�visitor   
class ConcreteElementA:public Element{
    private:
       string className;
    public:
       ConcreteElementA(string className);
       string getName();
       void accept(Visitor* visitor);
};
class ConcreteElementB:public Element{
    private:
       string className;
    public:
       ConcreteElementB(string className);
       string getName();
       void accept(Visitor* visitor);
};
#endif
