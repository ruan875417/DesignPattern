#ifndef ELEMENT_H
#define ELEMENT_H
#include<string>
using namespace std;
class Visitor;
//抽象被访问对象类，定义了一个统一的接口Accept
class Element{
    public:
       virtual void accept(Visitor* visitor)=0;
};
//具体被访问类，实现了Accept（）函数，接收一个visitor，在该函数中把自己传递给visitor   
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
