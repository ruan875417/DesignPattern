#include<iostream>
using namespace std;
///////////////////////////////////////////
// 球员  
class Player{
   protected:
      string name;
   public:
      Player(string name){ this->name=name; }
      virtual void attack()=0;
      virtual void defense()=0;
}; 
// 前锋类  
class Forwards:public Player{ 
   public:
      Forwards(string name):Player(name){}
      void attack(){
          cout<<"前锋 "<<name<<" 进攻"<<endl;
      }
      virtual void defense(){
          cout<<"前锋 "<<name<<" 防守"<<endl;
      }
};
// 中锋类  
class Center:public Player{ 
   public:
      Center(string name):Player(name){}
      void attack(){
          cout<<"中锋 "<<name<<" 进攻"<<endl;
      }
      virtual void defense(){
          cout<<"中锋 "<<name<<" 防守"<<endl;
      }
};
// 后卫类 
class Guard:public Player{ 
   public:
      Guard(string name):Player(name){}
      void attack(){
          cout<<"后卫 "<<name<<" 进攻"<<endl;
      }
      virtual void defense(){
          cout<<"后卫 "<<name<<" 防守"<<endl;
      }
};
// 外籍中锋  
class ForeignCenter{ 
   private:
      string name;
   public:
      void setName(string name){ this->name=name; }
      string getName(){ return name; }
      void foreignattack(){
          cout<<"外籍中锋 "<<name<<" 进攻"<<endl;
      }
      virtual void foreigndefense(){
          cout<<"外籍中锋 "<<name<<" 防守"<<endl;
      }
};
// 翻译者类  
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
    Player* forwards=new Forwards("巴蒂尔");
    forwards->attack();
    Player* center=new Center("麦克格雷迪");
    center->attack();
    Player* foreignCenter=new Translater("姚明");
    foreignCenter->attack();
    foreignCenter->defense();
    delete forwards;
    delete center;
    delete foreignCenter;
    system("pause");
    return 0;
}
