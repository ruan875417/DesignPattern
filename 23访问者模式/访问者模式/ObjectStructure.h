#ifndef OBJECTSTRUCTURE_H
#define OBJECTSTRUCTURE_H
#include "Visitor.h"
#include "Element.h"
#include<list>
//对象结构 拥有一组元素的组合对象
class ObjectStructure{
   private:
      list<Element*> elementlist;
   public:
      void attach(Element* element){
         elementlist.push_back(element);
      }    
      void detach(Element* element){
         elementlist.remove(element);
      }    
      void display(Visitor* visitor){
         list<Element*>::iterator it;
         for(it=elementlist.begin();it!=elementlist.end();it++){
             (*it)->accept(visitor);
         }
      }
};
#endif
