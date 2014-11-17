#include<iostream>
#include<string>
using namespace std;
/*Originator 发起人： 负责创建一个备忘录Memento，用以记录当前时刻它的内部状态，并可使用备忘录恢复内部状态。
Memento 备忘录： 负责储存Originator对象的内部状态，并可以防止Originator以外的其他对象访问备忘录Mementor。
Caretaker 管理者： 负责保存好备忘录Mementor，不能对备忘录的内容进行操作或检查。
Memento模式比较使用与功能比较复杂的，但需要维护或记录属性历史的类，或者需要保存的属性只是众多属性中的一个小部分， Originator可以根据
保存的Mementor信息还原到前一状态。*/
// 备忘录类 
class Memento{
   private:
      string state;
   public:
      Memento(string state){ this->state = state; }
      string getState(){ return state; }
};
// 发起人类  
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
// 管理者类   
class Caretaker{
   private:
      Memento* memento;
   public:
      Caretaker(){ memento=NULL; }    
      void setMemento(Memento* memento){ this->memento=memento; }
      Memento* getMemento(){ return memento; }
};
//客户端： 
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
