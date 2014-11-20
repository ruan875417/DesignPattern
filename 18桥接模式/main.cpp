#include<iostream>
#include "HandsetBrand.h"
using namespace std;
/********************************************** 
* 桥接模式原理： 
*   将抽象部分和它的实现部分分离，使它们都可以独 
* 立地变化。 
*   抽象与它的实现分离，这并不是说，让抽象类与其 
* 派生类分离，因为这没有任何意义。实现指的是抽象 
* 类和它的派生类用来实现自己的对象。 

* 总结： 
*   1、实现系统可能有多角度分类，每一种分类都有可能有变化，那么久把这种多 
*      角度分离出来让它们独立变化，减少它们之间的耦合。 
*   2、只要真正深入理解设计原则，很多设计模式其实就是原则的应用而已，或许 
*      在不知不觉中就在使用设计模式了。 
*   3、对象的继承关系是在编译时就定义好了，所以无法在运行时改变从父类继承 
*      的实现。子类的实现与它的父类有非常紧密的依赖关系，以至于父类实现中 
*      的任何变化必然会导致子类发生变化。当你需要复用子类时，如果继承下来 
*      的实现不适合解决新的问题，则父类必须重写或被其他更适合的类替换。这 
*      种依赖关系限制了灵活性并最终限制了复用性。 
************************************************************************/  
int main(){
    HandsetBrand* handsetBrand;
    handsetBrand=new HandsetBrandM;
    
    handsetBrand->setHandsetSoft(new HandsetGame);
    handsetBrand->run();
    
    handsetBrand->setHandsetSoft(new HandsetAddressList);
    handsetBrand->run();
    
    handsetBrand=new HandsetBrandN;
    handsetBrand->setHandsetSoft(new HandsetGame);
    handsetBrand->run();
    
    handsetBrand->setHandsetSoft(new HandsetAddressList);
    handsetBrand->run();
    
    system("pause");
    return 0;
}
