#include<iostream>
#include<map>
using namespace std;
//�������Ԫ��  
class Flyweight{
    public:
        virtual void operation(int i)=0;     
};
//���������
class ConcreteFlyweight:public Flyweight{
    public:
       void operation(int i){
           cout<<"����flyweight:"<<i<<endl;
       }
};
//�����������  
class UnshareConcreteFlyweight:public Flyweight{
    public:
       void operation(int i){
           cout<<"������ľ���flyweight:"<<i<<endl;
       }
};
//��Ԫ���� 
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
