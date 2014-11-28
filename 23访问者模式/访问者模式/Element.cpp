#include "Element.h"
#include "Visitor.h"
ConcreteElementA::ConcreteElementA(string className){
    this->className=className;
}
string ConcreteElementA::getName(){
    return className;
}
void ConcreteElementA::accept(Visitor* visitor){
    visitor->visitConcreteElementA(this);
}


ConcreteElementB::ConcreteElementB(string className){
    this->className=className;
}
string ConcreteElementB::getName(){
    return className;
}
void ConcreteElementB::accept(Visitor* visitor){
    visitor->visitConcreteElementB(this);
}
