#include<iostream>
using namespace std;
/********************************************** 
* 模板方法模式原理： 
*   定义一个操作中的算法的骨架，而将一些步 
* 骤延迟到子类中。模板方法使得子类可以不改 
* 变一个算法的结构即可重定义该算法的某些特 
* 定步骤。 
***********************************************/  
//---------------------------------------------  
// 抽象算法类  
//    实现了一个模板方法，定义了算法骨架，  
// 具体子类将重定义vPrimitiveOperation以实现  
// 一个算法的步骤。  
class AbstractClass{
   public:
      virtual void primitiveOperation1(){}
      virtual void primitiveOperation2(){}
      void templateMethod(){
           primitiveOperation1();
           primitiveOperation2();
      }
};
/*实现类*/
class ConcreteClassA:public AbstractClass{
   public:
      void primitiveOperation1(){ cout<<"操作A的具体实现"<<endl; }
      void primitiveOperation2(){ cout<<"操作A的具体实现"<<endl; }
};
class ConcreteClassB:public AbstractClass{
   public:
      void primitiveOperation1(){ cout<<"操作B的具体实现"<<endl; }
      void primitiveOperation2(){ cout<<"操作B的具体实现"<<endl; }
};

int main(){
    AbstractClass* abstractClass;
    abstractClass=new ConcreteClassA;
    abstractClass->templateMethod();
    delete abstractClass;
    
    abstractClass=new ConcreteClassB;
    abstractClass->templateMethod();
    delete abstractClass;
    
    system("pause");
    return 0;
}
