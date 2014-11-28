#include "ObjectStructure.h"
int main(){
    ObjectStructure* objectStructure=new ObjectStructure;
    objectStructure->attach(new ConcreteElementA("ConcreteElementA"));
    objectStructure->attach(new ConcreteElementB("ConcreteElementB"));
    
    ConcreteVisitor1* concreteVisitor1=new ConcreteVisitor1;
    objectStructure->display(concreteVisitor1);
    
    ConcreteVisitor2* concreteVisitor2=new ConcreteVisitor2;
    objectStructure->display(concreteVisitor2);
    
    delete concreteVisitor2;
    delete concreteVisitor1;
    delete objectStructure;
    
    system("pause");
    return 0;
}
