#include<iostream>
using namespace std;
///////////////////////////////////////////
// ��Ա  
class Player{
   protected:
      string name;
   public:
      Player(string name){ this->name=name; }
      virtual void attack()=0;
      virtual void defense()=0;
}; 
// ǰ����  
class Forwards:public Player{ 
   public:
      Forwards(string name):Player(name){}
      void attack(){
          cout<<"ǰ�� "<<name<<" ����"<<endl;
      }
      virtual void defense(){
          cout<<"ǰ�� "<<name<<" ����"<<endl;
      }
};
// �з���  
class Center:public Player{ 
   public:
      Center(string name):Player(name){}
      void attack(){
          cout<<"�з� "<<name<<" ����"<<endl;
      }
      virtual void defense(){
          cout<<"�з� "<<name<<" ����"<<endl;
      }
};
// ������ 
class Guard:public Player{ 
   public:
      Guard(string name):Player(name){}
      void attack(){
          cout<<"���� "<<name<<" ����"<<endl;
      }
      virtual void defense(){
          cout<<"���� "<<name<<" ����"<<endl;
      }
};
// �⼮�з�  
class ForeignCenter{ 
   private:
      string name;
   public:
      void setName(string name){ this->name=name; }
      string getName(){ return name; }
      void foreignattack(){
          cout<<"�⼮�з� "<<name<<" ����"<<endl;
      }
      virtual void foreigndefense(){
          cout<<"�⼮�з� "<<name<<" ����"<<endl;
      }
};
// ��������  
class Translater:public Player{
   private:
      ForeignCenter foreignCenter;
   public:
      Translater(string name):Player(name){
          foreignCenter.setName(name);
      }
      void attack(){
          foreignCenter.foreignattack();
      }
      virtual void defense(){
          foreignCenter.foreigndefense();
      }
};
int main(){
    Player* forwards=new Forwards("�͵ٶ�");
    forwards->attack();
    Player* center=new Center("��˸��׵�");
    center->attack();
    Player* foreignCenter=new Translater("Ҧ��");
    foreignCenter->attack();
    foreignCenter->defense();
    delete forwards;
    delete center;
    delete foreignCenter;
    system("pause");
    return 0;
}
