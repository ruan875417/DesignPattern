#include<iostream>
#include<string>
#include<vector>
using namespace std;
typedef string object;
/********************************************** 
* ������ģʽԭ�� 
*   �ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ�أ� 
* ���ֲ���¶�ö�����ڲ���ʾ�� 
*   ������Ҫ����һ���ۼ����󣬶��Ҳ�����Щ���� 
* ��ʲô����Ҫ������ʱ�����Ӧ�ÿ���ʹ�õ��� 
* ��ģʽ�� 
*   ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ� 
* ��������ǰ��һ���ͳһ�Ľӿڡ� 
***********************************************/  
//---------------------------------------------  
//  Iterator������������  
//  ���ڶ���õ���ʼ���󣬵õ���һ�������ж���  
// �񵽽�β����ǰ����ȳ��󷽷���ͳһ�ӿڡ�  
class Iterator{
    public:
       Iterator(){}
       virtual object first()=0;
       virtual object next()=0;
       virtual bool isDone()=0;
       virtual object curItem()=0;
};
//---------------------------------------------  
// Aggregate�ۼ�������  
//  ����������  
class Aggregate{
   public:
       Aggregate(){}
       virtual Iterator* createIterator()=0;
       virtual object getItem(int index )=0;
       virtual void setItem(object item)=0;
       virtual int getSize()=0;
};
// ConcreteIterator�����������  
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
// ConcreteAggregate����ۼ���     
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
    aggregate->setItem("�˿�1");
    aggregate->setItem("�˿�2");
    aggregate->setItem("�˿�3");
    aggregate->setItem("�˿�4");
    aggregate->setItem("�˿�5");
    aggregate->setItem("�˿�6");
    
    Iterator* iterator=aggregate->createIterator();
    for(;!iterator->isDone();iterator->next())
       cout<<iterator->curItem()<<" ����Ʊ"<<endl;

    system("pause");
    return 0;
}
