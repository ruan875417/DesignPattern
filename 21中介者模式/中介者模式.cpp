#include<iostream>
#include<string> 
using namespace std;

class Colleague;
class Mediator{
    public:
        virtual void send(string message,Colleague* colleague)=0;
};
class Colleague{
    protected:
        Mediator* mediator;
    public:
        Colleague(Mediator* mediator){
            this->mediator=mediator;
        }
        virtual void send(string message)=0;
        virtual void notify(string message)=0;
};
class ConcreteMediator:public Mediator{
    private:
        Colleague* colleague1;
        Colleague* colleague2;
    public:
        void addColleague1(Colleague* colleague){
            colleague1=colleague;
        }
        void addColleague2(Colleague* colleague){
            colleague2=colleague;
        }
        void send(string message,Colleague* colleague){
            if(colleague==colleague1){
                colleague2->notify(message);
            }else if(colleague==colleague2){
                colleague1->notify(message);
            }
        }
};


class ConcreteColleague1:public Colleague{
    public:
        ConcreteColleague1(Mediator* mediator):Colleague(mediator){}
        void send(string message){ 
            mediator->send(message,this);
        }
        void notify(string message){
            cout<<"同事1得到信息："<<message<<endl;
        }
};
class ConcreteColleague2:public Colleague{
    public:
        ConcreteColleague2(Mediator* mediator):Colleague(mediator){}
        void send(string message){ 
            mediator->send(message,this);
        }
        void notify(string message){
            cout<<"同事2得到信息："<<message<<endl;
        }
};

int main(){
    ConcreteMediator* concreteMediator=new ConcreteMediator;
    //让具体同事类认识中介者对象 
    ConcreteColleague1* concreteColleague1=new ConcreteColleague1(concreteMediator);
    ConcreteColleague2* concreteColleague2=new ConcreteColleague2(concreteMediator);
    //让中介者认识具体同事类 
    concreteMediator->addColleague1(concreteColleague1);
    concreteMediator->addColleague2(concreteColleague2);
    //具体同事类对象的发送信息都通过中介者转发 
    concreteColleague1->send("吃过饭了吗？（同事1发送）");
    concreteColleague2->send("没有，要请客吗？（同事2发送）");
    
    delete concreteColleague1;
    delete concreteColleague2;
    delete concreteMediator;
    
    system("pause");
    return 0; 
}
