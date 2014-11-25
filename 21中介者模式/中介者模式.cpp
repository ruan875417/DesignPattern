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
            cout<<"ͬ��1�õ���Ϣ��"<<message<<endl;
        }
};
class ConcreteColleague2:public Colleague{
    public:
        ConcreteColleague2(Mediator* mediator):Colleague(mediator){}
        void send(string message){ 
            mediator->send(message,this);
        }
        void notify(string message){
            cout<<"ͬ��2�õ���Ϣ��"<<message<<endl;
        }
};

int main(){
    ConcreteMediator* concreteMediator=new ConcreteMediator;
    //�þ���ͬ������ʶ�н��߶��� 
    ConcreteColleague1* concreteColleague1=new ConcreteColleague1(concreteMediator);
    ConcreteColleague2* concreteColleague2=new ConcreteColleague2(concreteMediator);
    //���н�����ʶ����ͬ���� 
    concreteMediator->addColleague1(concreteColleague1);
    concreteMediator->addColleague2(concreteColleague2);
    //����ͬ�������ķ�����Ϣ��ͨ���н���ת�� 
    concreteColleague1->send("�Թ������𣿣�ͬ��1���ͣ�");
    concreteColleague2->send("û�У�Ҫ����𣿣�ͬ��2���ͣ�");
    
    delete concreteColleague1;
    delete concreteColleague2;
    delete concreteMediator;
    
    system("pause");
    return 0; 
}
