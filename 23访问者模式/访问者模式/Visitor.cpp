#include<iostream>
#include "Visitor.h"
using namespace std;

void ConcreteVisitor1::visitConcreteElementA(ConcreteElementA* concreteElementA){
     cout<<concreteElementA->getName()<<"��ConcreteVisitor1����"<<endl; 
}
void ConcreteVisitor1::visitConcreteElementB(ConcreteElementB* concreteElementB){
     cout<<concreteElementB->getName()<<"��ConcreteVisitor1����"<<endl; 
}


void ConcreteVisitor2::visitConcreteElementA(ConcreteElementA* concreteElementA){
     cout<<concreteElementA->getName()<<"��ConcreteVisitor2����"<<endl; 
}
void ConcreteVisitor2::visitConcreteElementB(ConcreteElementB* concreteElementB){
     cout<<concreteElementB->getName()<<"��ConcreteVisitor2����"<<endl;
}
