#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
/*�����Ʒ��Product������Ϊ�����Ʒ�Ļ��࣬�ṩͳһ�Ľӿڣ�Ҳ�ǹ�����Ҫ���ص����͡�*/
class Operation{
   private:
       double numberA;
       double numberB;
       double result;
   public:
       Operation(){ numberA=0;numberB=0;result=0; }
       double getNumberA(){ return numberA; }
       double getNumberB(){ return numberB; }
       void setNumberA(double number){ numberA=number; }
       void setNumberB(double number){ numberB=number; }
       virtual double getResult(){  return result; }
};
/*�����Ʒ��Concrete Product��*/ 
class OperationAdd:public Operation{
      public:
         double getResult(){ return getNumberA()+getNumberB(); }   
}; 
class OperationSub:public Operation{
      public:
         double getResult(){ return getNumberA()-getNumberB(); }   
}; 
class OperationMul:public Operation{
      public:
        double getResult(){ return getNumberA()*getNumberB(); }   
}; 
class OperationDiv:public Operation{
      public:
         double getResult(){ 
             if(getNumberB()==0)
                return 0;
             else
                return getNumberA()/getNumberB();
          } 
}; 
/*�����ӿ�*/
class IFactory{
   public:
       virtual Operation* CreateOperation(){};
};
/*���幤����*/
class AddFactory:public IFactory{
   public:
      Operation* CreateOperation(){ return new OperationAdd; }
};
class SubFactory:public IFactory{
   public:
      Operation* CreateOperation(){ return new OperationSub; }
};
class MulFactory:public IFactory{
   public:
      Operation* CreateOperation(){ return new OperationMul; }
};
class DivFactory:public IFactory{
   public:
      Operation* CreateOperation(){ return new OperationDiv; }
};
int main(){
    IFactory* operFactory = new MulFactory;
    Operation* oper=operFactory->CreateOperation();
    oper->setNumberA(4);
    oper->setNumberB(5);
    cout<<oper->getResult()<<endl;
    delete operFactory;
    delete oper;
    system("pause");
    return 0;
}
