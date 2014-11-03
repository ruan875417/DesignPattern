#include<iostream>
using namespace std;
//////////////////////////////////////////////////
/********************************************** 
* ���ģʽԭ�� 
*   Ϊ��ϵͳ�е�һ��ӿ��ṩһ��һ�µĽ��棬 
*  ��ģʽ������һ���߲�ӿڣ�����ӿ�ʹ���� 
*  һ��ϵͳ��������ʹ�á� 
***********************************************/  
// ��ϵͳ��  
//      ʵ����ϵͳ�Ĺ��ܣ�����Facade����ָ  
//  �ɵ�����ע��������û��Facade���κ���  
//  Ϣ����û�ж�Facade�Ķ������á�  
class SubSystem1{
   public:
      void method1(){ cout<<"��ϵͳ����1"<<endl; }
};
class SubSystem2{
   public:
      void method2(){ cout<<"��ϵͳ����2"<<endl; }
};
class SubSystem3{
   public:
      void method3(){ cout<<"��ϵͳ����3"<<endl; }
};
class SubSystem4{
   public:
      void method4(){ cout<<"��ϵͳ����4"<<endl; }
};
///////////////////////////////////////////////////////
// �����  
//      ��Ҫ�˽���ϵͳ�ķ��������ԣ�������  
// �ϣ��Ա������á�  
//      ֪����Щ���ฺ�������󣬽��ͻ���  
// ���������ʵ�����ϵͳ����  
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
//�ͻ��� 
int main(){
    Facade* facade=new Facade;
    facade->methodA();
    facade->methodB();
    system("pause");
    return 0;
}
