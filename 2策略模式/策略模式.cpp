#include<iostream>
using namespace std;
/////////////////////////////////////////////////////
/*���Ի���*/
class Strategy{//��Ҫ�����麯�� 
    public:
        virtual void algorithmInterface(){};
};
/*���������*/
class ConcreteStrategyA:public Strategy{//�������࣬�Ը����麯�����о���ʵ�� 
    public:
        void algorithmInterface(){ cout<<"�㷨A�ľ���ʵ��"<<endl;}
};
class ConcreteStrategyB:public Strategy{//�������࣬�Ը����麯�����о���ʵ�� 
    public:
        void algorithmInterface(){ cout<<"�㷨B�ľ���ʵ��"<<endl;}
};
class ConcreteStrategyC:public Strategy{//�������࣬�Ը����麯�����о���ʵ�� 
    public:
        void algorithmInterface(){ cout<<"�㷨C�ľ���ʵ��"<<endl;}
};
/*������*/
class Context{//������,���ݴ������Ĳ���,ѡ�����ĳ������
    private:
       Strategy* stategy;
    public:
       Context( Strategy* pstategy){ stategy=pstategy; }
       void ContextInterface(){ stategy->algorithmInterface(); }
            
};
/*�ͻ���*/
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
