#include<iostream>
#include<vector>
using namespace std;
/////////////////////////////////////
/********************************************** 
* 建造者模式原理：[生成器模式] 
*   将一个复杂对象的构建与它的表示分离，使 
* 得同样的构建过程可以创建不同的表示。 
*   如果我们使用了创造者模式，那么用户就只 
* 需要建造的类型就可以得到它们，而具体建造 
* 的过程和细节就不需要知道了。 
***********************************************/  
/************************************************************************ 
* 小结： 
*   1、建造者模式主要用于创建一些复杂的对象，这些对象间的建造顺序通 
*      常是稳定的，但对象内部的构建通常面临着复杂的变化。 
*   2、建造者模式的好处在于使得建造代码与表示代码分离，由于建造者隐 
*      藏了该产品是如何组装的，所以若需要改变一个产品内部表示，只需 
*      要再定义一个具体的建造者就可以了。 
*   3、建造者模式是在当创建复杂对象的算法应该独立于该对象的组成部分 
*      以及它们的装配方式时适用的模式。 
************************************************************************/ 
// 具体产品类  
//      一个产品由多个部件组成。  
class Product{
    private:
       vector<string> part;
    public:
       void add(string part){ this->part.push_back(part); }
       void show(){
           cout<<"产品创建"<<endl;
           vector<string>::iterator it;
           for(it=part.begin();it!=part.end();++it)
           {
               cout<<"部件:"<<*it<<endl;                                   
           } 
       }
};
// 抽象建造者类  
//    为创建一个Product对象的各个部件指定的抽象接口。  
class Build{
    public:
       virtual void buildPartA(){}
       virtual void buildPartB(){}
       virtual Product* getResult(){ return NULL; }
};
// 具体建造者类  
//    实现Builder接口，构造和装配各个部件。  
class ConcreteBuild1:public Build{
    private:
       Product* product;
    public:
       ConcreteBuild1(){ product=new Product; }
       void buildPartA(){ product->add("部件1"); }
       void buildPartB(){ product->add("部件2"); }
       Product* getResult(){ return product; }
       ~ConcreteBuild1(){
            if(product!=NULL){
               delete product;
               product=NULL;
            }
       } 
};
class ConcreteBuild2:public Build{
    private:
       Product* product;
    public:
       ConcreteBuild2(){ product=new Product; }
       void buildPartA(){ product->add("部件A"); }
       void buildPartB(){ product->add("部件B"); }
       Product* getResult(){ return product; }
       ~ConcreteBuild2(){
            if(product!=NULL){
               delete product;
               product=NULL;
            }
       }
};
// 指挥者类  
//    构建一个使用Builder接口的对象。 
class Director{
   public:
      void construct(Build* build){
         build->buildPartA();
         build->buildPartB();
      }
};
int main(){
    Director* director=new Director;
    Build* build1=new ConcreteBuild1;
    director->construct(build1);
    Product* product1=build1->getResult();
    product1->show();
    
    Build* build2=new ConcreteBuild2;
    director->construct(build2);
    Product* product2=build2->getResult();
    product2->show();
    
    system("pause");
    return 0;
}
