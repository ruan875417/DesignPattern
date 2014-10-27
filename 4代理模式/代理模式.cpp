#include<iostream>
#include<string>
using namespace std;
/*����ӿ�*/ 
class IGiveGift{
    public:
        virtual void giveDolls()=0;
        virtual void giveFlowers()=0;
        virtual void giveChocolate()=0;
};
/*��׷����*/ 
class SchoolGirl{
    private:
        string name;
    public:
        SchoolGirl(){};
        SchoolGirl(string name){ this->name=name; }
        string getName(){ return name; }
        void setName(string name){ this->name=name; } 
};
/*׷������*/ 
class Persuit:public IGiveGift{
      private:
           SchoolGirl mm;
        public:
           Persuit(){}
           Persuit(SchoolGirl mm){ this->mm=mm; }
           void giveDolls(){ cout<<mm.getName()<<"����������"<<endl; }
           void giveFlowers(){ cout<<mm.getName()<<"���㻨"<<endl; }
           void giveChocolate(){ cout<<mm.getName()<<"�����ɿ���"<<endl; }
};
/*������*/ 
class Proxy:public IGiveGift{
    private:
        Persuit* gg;
    public:
        Proxy(SchoolGirl mm){ gg=new Persuit(mm); }
        void giveDolls(){ gg->giveDolls(); }
        void giveFlowers(){ gg->giveFlowers(); }
        void giveChocolate(){ gg->giveChocolate(); }
};
/*�ͻ���*/ 
int main(){
    SchoolGirl mm("jiaojiao");
    Proxy proxy(mm);
    proxy.giveDolls();
    proxy.giveFlowers();
    proxy.giveChocolate(); 
    system("pause");
    return 0;
}
