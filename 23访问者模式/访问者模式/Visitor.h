#ifndef VISITOR_H 
#define VISITOR_H
#include "Element.h"
//抽象访问者类 
class Visitor{
    public:
        virtual void visitConcreteElementA(ConcreteElementA* concreteElementA)=0;
        virtual void visitConcreteElementB(ConcreteElementB* concreteElementB)=0;
};
//具体访问者类
class ConcreteVisitor1:public Visitor{
    public:
        void visitConcreteElementA(ConcreteElementA* concreteElementA);
        void visitConcreteElementB(ConcreteElementB* concreteElementB);
};
class ConcreteVisitor2:public Visitor{
    public:
        void visitConcreteElementA(ConcreteElementA* concreteElementA);
        void visitConcreteElementB(ConcreteElementB* concreteElementB);
};
#endif
