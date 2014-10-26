#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
/*策略基类*/
class Strategy{//主要定义虚函数 
    public:
        virtual void algorithmInterface(){};
};
/*具体策略类*/
class ConcreteStrategyA:public Strategy{//策略子类，对父类虚函数进行具体实现 
    public:
        void algorithmInterface(){ cout<<"算法A的具体实现"<<endl;}
};
class ConcreteStrategyB:public Strategy{//策略子类，对父类虚函数进行具体实现 
    public:
        void algorithmInterface(){ cout<<"算法B的具体实现"<<endl;}
};
class ConcreteStrategyC:public Strategy{//策略子类，对父类虚函数进行具体实现 
    public:
        void algorithmInterface(){ cout<<"算法C的具体实现"<<endl;}
};
/*调度类*/
class Context{//调度类,根据传进来的参数,选择具体某个策略
    private:
       Strategy* stategy;
    public:
       Context( Strategy* pstategy){ stategy=pstategy; }
       void ContextInterface(){ stategy->algorithmInterface(); }
            
};
/*客户端*/
int main(){
    Context* context;
    context=new Context(new ConcreteStrategyA);
    context->ContextInterface(); 
    context=new Context(new ConcreteStrategyB);
    context->ContextInterface(); 
    context=new Context(new ConcreteStrategyC);
    context->ContextInterface(); 
    system("pause");
    return 0;
}
