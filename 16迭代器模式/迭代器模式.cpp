#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef string object;
/********************************************** 
* 迭代器模式原理： 
*   提供一种方法顺序访问一个聚合对象中各个元素， 
* 而又不暴露该对象的内部表示。 
*   当你需要访问一个聚集对象，而且不管这些对象 
* 是什么都需要遍历的时候，你就应该考虑使用迭代 
* 器模式。 
*   遍历不同的聚集结构提供如开始、下一个、是否 
* 结束、当前哪一项等统一的接口。 
***********************************************/  
//---------------------------------------------  
//  Iterator迭代器抽象类  
//  用于定义得到开始对象，得到下一个对象，判断是  
// 否到结尾、当前对象等抽象方法，统一接口。  
class Iterator{
    public:
       Iterator(){}
       virtual object first()=0;
       virtual object next()=0;
       virtual bool isDone()=0;
       virtual object curItem()=0;
};
//---------------------------------------------  
// Aggregate聚集抽象类  
//  创建迭代器  
class Aggregate{
   public:
       Aggregate(){}
       virtual Iterator* createIterator()=0;
       virtual object getItem(int index )=0;
       virtual void setItem(object item)=0;
       virtual int getSize()=0;
};
// ConcreteIterator具体迭代器类  
class ConcreteIterator:public Iterator{
    private:
       Aggregate* aggregate;
       int current;
    public:
       ConcreteIterator(Aggregate* aggregate){ 
           this->aggregate = aggregate; 
           current=0;
       }
       object first(){ return aggregate->getItem(0); }
       object next(){
           current++;
           if(current<aggregate->getSize()){
              return aggregate->getItem(current);
           }
       }
       bool isDone(){ 
           return current==aggregate->getSize();
       }
       object curItem(){ return aggregate->getItem(current); }
};
// ConcreteAggregate具体聚集类     
class ConcreteAggregate:public Aggregate{
   private:
       vector<object> items;
   public:
       ConcreteAggregate(){}
       Iterator* createIterator(){ new ConcreteIterator(this); };
       object getItem(int index ){ return items.at(index); }
       void setItem(object item){ items.push_back(item); }
       int getSize(){ return items.size(); }
};

int main(){
    Aggregate* aggregate=new ConcreteAggregate();
    aggregate->setItem("乘客1");
    aggregate->setItem("乘客2");
    aggregate->setItem("乘客3");
    aggregate->setItem("乘客4");
    aggregate->setItem("乘客5");
    aggregate->setItem("乘客6");
    
    Iterator* iterator=aggregate->createIterator();
    for(;!iterator->isDone();iterator->next())
       cout<<iterator->curItem()<<" 请买票"<<endl;

    system("pause");
    return 0;
}
