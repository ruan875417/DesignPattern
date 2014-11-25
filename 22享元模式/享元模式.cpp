#include<iostream>
#include<map>
using namespace std;
//抽象的享元类  
class Flyweight{
    public:
        virtual void operation(int i)=0;     
};
//共享的子类
class ConcreteFlyweight:public Flyweight{
    public:
       void operation(int i){
           cout<<"具体flyweight:"<<i<<endl;
       }
};
//不共享的子类  
class UnshareConcreteFlyweight:public Flyweight{
    public:
       void operation(int i){
           cout<<"不共享的具体flyweight:"<<i<<endl;
       }
};
//享元工厂 
class FlyweightFactory{
   private:
      map<string,Flyweight*> flyweights;
   public:
      FlyweightFactory(){
         flyweights["X"]=new ConcreteFlyweight;
         flyweights["Y"]=new ConcreteFlyweight;
         flyweights["Z"]=new ConcreteFlyweight;
      }
      Flyweight* getFlyweight(string key){
         if(!flyweights.count(key)){
            flyweights[key]=new ConcreteFlyweight;
         }
         return flyweights[key];
      }
}; 
int main(){
    int i=100;
    FlyweightFactory* flyweightFactory=new FlyweightFactory;
    
    Flyweight* fx=flyweightFactory->getFlyweight("X");
    fx->operation(--i);
    
    Flyweight* fy=flyweightFactory->getFlyweight("Y");
    fy->operation(--i);
    
    Flyweight* fz=flyweightFactory->getFlyweight("Z");
    fz->operation(--i);
    
    UnshareConcreteFlyweight* uf=new UnshareConcreteFlyweight;
    uf->operation(--i);
    
    delete flyweightFactory;
    delete fx;
    delete fy;
    delete fz;
    delete uf;
    
    system("pause");
    return 0;
}
