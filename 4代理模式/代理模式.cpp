#include<iostream>
#include<string>
using namespace std;
/*送礼接口*/ 
class IGiveGift{
    public:
        virtual void giveDolls()=0;
        virtual void giveFlowers()=0;
        virtual void giveChocolate()=0;
};
/*被追求类*/ 
class SchoolGirl{
    private:
        string name;
    public:
        SchoolGirl(){};
        SchoolGirl(string name){ this->name=name; }
        string getName(){ return name; }
        void setName(string name){ this->name=name; } 
};
/*追求者类*/ 
class Persuit:public IGiveGift{
      private:
           SchoolGirl mm;
        public:
           Persuit(){}
           Persuit(SchoolGirl mm){ this->mm=mm; }
           void giveDolls(){ cout<<mm.getName()<<"送你洋娃娃"<<endl; }
           void giveFlowers(){ cout<<mm.getName()<<"送你花"<<endl; }
           void giveChocolate(){ cout<<mm.getName()<<"送你巧克力"<<endl; }
};
/*代理类*/ 
class Proxy:public IGiveGift{
    private:
        Persuit* gg;
    public:
        Proxy(SchoolGirl mm){ gg=new Persuit(mm); }
        void giveDolls(){ gg->giveDolls(); }
        void giveFlowers(){ gg->giveFlowers(); }
        void giveChocolate(){ gg->giveChocolate(); }
};
/*客户端*/ 
int main(){
    SchoolGirl mm("jiaojiao");
    Proxy proxy(mm);
    proxy.giveDolls();
    proxy.giveFlowers();
    proxy.giveChocolate(); 
    system("pause");
    return 0;
}
