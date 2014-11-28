#include<iostream>
#include "Visitor.h"
using namespace std;

void ConcreteVisitor1::visitConcreteElementA(ConcreteElementA* concreteElementA){
     cout<<concreteElementA->getName()<<"被ConcreteVisitor1访问"<<endl; 
}
void ConcreteVisitor1::visitConcreteElementB(ConcreteElementB* concreteElementB){
     cout<<concreteElementB->getName()<<"被ConcreteVisitor1访问"<<endl; 
}


void ConcreteVisitor2::visitConcreteElementA(ConcreteElementA* concreteElementA){
     cout<<concreteElementA->getName()<<"被ConcreteVisitor2访问"<<endl; 
}
void ConcreteVisitor2::visitConcreteElementB(ConcreteElementB* concreteElementB){
     cout<<concreteElementB->getName()<<"被ConcreteVisitor2访问"<<endl;
}
