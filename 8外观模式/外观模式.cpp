#include<iostream>
using namespace std;
//////////////////////////////////////////////////
/********************************************** 
* 外观模式原理： 
*   为子系统中的一组接口提供一个一致的界面， 
*  此模式定义了一个高层接口，这个接口使得这 
*  一子系统更加容易使用。 
***********************************************/  
// 子系统类  
//      实现子系统的功能，处理Facade对象指  
//  派的任务。注意子类中没有Facade的任何信  
//  息，即没有对Facade的对象引用。  
class SubSystem1{
   public:
      void method1(){ cout<<"子系统方法1"<<endl; }
};
class SubSystem2{
   public:
      void method2(){ cout<<"子系统方法2"<<endl; }
};
class SubSystem3{
   public:
      void method3(){ cout<<"子系统方法3"<<endl; }
};
class SubSystem4{
   public:
      void method4(){ cout<<"子系统方法4"<<endl; }
};
///////////////////////////////////////////////////////
// 外观类  
//      需要了解子系统的方法或属性，进行组  
// 合，以备外界调用。  
//      知道哪些子类负责处理请求，将客户的  
// 请求代理给适当的子系统对象。  
class Facade{
   private:
      SubSystem1* subsys1;
      SubSystem2* subsys2;
      SubSystem3* subsys3;
      SubSystem4* subsys4;
   public:
      Facade();
      void methodA();
      void methodB();
      ~Facade(); 
};
Facade::Facade(){
   subsys1=new SubSystem1;
   subsys2=new SubSystem2;
   subsys3=new SubSystem3;
   subsys4=new SubSystem4;
} 
void Facade::methodA(){
   cout<<"methodA"<<endl;
   subsys1->method1();
   subsys2->method2();
   subsys3->method3();
}
void Facade::methodB(){
   cout<<"methodB"<<endl;
   subsys1->method1();
   subsys2->method2();
   subsys4->method4();
}
Facade::~Facade(){
   if(subsys1!=NULL)
      delete subsys1;
   if(subsys2!=NULL)
      delete subsys2;
   if(subsys3!=NULL)
      delete subsys3;
   if(subsys4!=NULL)
      delete subsys4;
} 
/////////////////////////////////////////////////////////
//客户端 
int main(){
    Facade* facade=new Facade;
    facade->methodA();
    facade->methodB();
    system("pause");
    return 0;
}
