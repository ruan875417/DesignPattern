#include<iostream>
using namespace std;
/********************************************** 
* ģ�巽��ģʽԭ�� 
*   ����һ�������е��㷨�ĹǼܣ�����һЩ�� 
* ���ӳٵ������С�ģ�巽��ʹ��������Բ��� 
* ��һ���㷨�Ľṹ�����ض�����㷨��ĳЩ�� 
* �����衣 
***********************************************/  
//---------------------------------------------  
// �����㷨��  
//    ʵ����һ��ģ�巽�����������㷨�Ǽܣ�  
// �������ཫ�ض���vPrimitiveOperation��ʵ��  
// һ���㷨�Ĳ��衣  
class AbstractClass{
   public:
      virtual void primitiveOperation1(){}
      virtual void primitiveOperation2(){}
      void templateMethod(){
           primitiveOperation1();
           primitiveOperation2();
      }
};
/*ʵ����*/
class ConcreteClassA:public AbstractClass{
   public:
      void primitiveOperation1(){ cout<<"����A�ľ���ʵ��"<<endl; }
      void primitiveOperation2(){ cout<<"����A�ľ���ʵ��"<<endl; }
};
class ConcreteClassB:public AbstractClass{
   public:
      void primitiveOperation1(){ cout<<"����B�ľ���ʵ��"<<endl; }
      void primitiveOperation2(){ cout<<"����B�ľ���ʵ��"<<endl; }
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
