#include<iostream>
#include<string>
using namespace std;
/*Originator �����ˣ� ���𴴽�һ������¼Memento�����Լ�¼��ǰʱ�������ڲ�״̬������ʹ�ñ���¼�ָ��ڲ�״̬��
Memento ����¼�� ���𴢴�Originator������ڲ�״̬�������Է�ֹOriginator���������������ʱ���¼Mementor��
Caretaker �����ߣ� ���𱣴�ñ���¼Mementor�����ܶԱ���¼�����ݽ��в������顣
Mementoģʽ�Ƚ�ʹ���빦�ܱȽϸ��ӵģ�����Ҫά�����¼������ʷ���࣬������Ҫ���������ֻ���ڶ������е�һ��С���֣� Originator���Ը���
�����Mementor��Ϣ��ԭ��ǰһ״̬��*/
// ����¼�� 
class Memento{
   private:
      string state;
   public:
      Memento(string state){ this->state = state; }
      string getState(){ return state; }
};
// ��������  
class Originator{
   private:
      string state;
   public:
      Originator(){};
      void setState(string state){ this->state=state; }
      Memento* createMemento(){ return new Memento(state); }
      void setMemento(Memento* memento){ state=memento->getState(); }
      void show(){ cout<<"State="<<state<<endl; }
};
// ��������   
class Caretaker{
   private:
      Memento* memento;
   public:
      Caretaker(){ memento=NULL; }    
      void setMemento(Memento* memento){ this->memento=memento; }
      Memento* getMemento(){ return memento; }
};
//�ͻ��ˣ� 
int main(){
   Originator* originator=new Originator;
   originator->setState("On");
   originator->show();
   
   Caretaker* caretaker=new Caretaker;
   caretaker->setMemento(originator->createMemento());
   
   originator->setState("Off");
   originator->show();
   
   originator->setMemento(caretaker->getMemento());
   originator->show();
   
   system("pause");
   return 0; 
}
