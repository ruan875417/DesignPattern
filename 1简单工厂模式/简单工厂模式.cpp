#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
/*抽象产品（Product）：作为具体产品的基类，提供统一的接口，也是工厂类要返回的类型。*/
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
/*具体产品（Concrete Product）*/ 
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

/*工厂类（Creator）：根据业务逻辑创建具体产品，由客户程序直接调用。*/
class OperationFactory{
    public:
       static Operation* creatOperation(char operate){
            switch(operate){
                 case '+':
                      return new OperationAdd;
                      break;
                 case '-':
                      return new OperationSub;
                      break;
                 case '*':
                      return new OperationMul;
                      break;
                 case '/':
                      return new OperationDiv;
                      break;
            }
       }
};

int main(){
    Operation *aa=NULL;
    aa=OperationFactory::creatOperation('+');
    aa->setNumberA(1);
    aa->setNumberB(2);
    cout<<aa->getResult()<<endl;
    delete aa;
    system("pause");
    return 0;
}
