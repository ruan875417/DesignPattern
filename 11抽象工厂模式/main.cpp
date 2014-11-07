#include "AbstractFactory.h"
/* 
参考网站：神秘果：http://www.shenmiguo.com/ 
定义： 
提供一个创建一系列相关或相互依赖对象的接口，而无需指定它们具体的类。 
理解： 
1.AbstractFactory是抽象工厂类，声明创建产品族的接口。具体工厂创建具体的产品族（Product Family），可以创建出分属于不同 
  产品等级的一个产品族中的所有对象。ConcreteFactory1和ConcreteFactory2分别生产2个不同产品族。举例：手机工厂生产的产品族 
  中，产品有Linux系统的手机和Windows系统的手机。PC工厂生产的产品族中，产品有Linux系统的PC和Windows系统的PC。 
2.AbstractProductA和AbstractProductB是产品基类。它们的派生类是同产品等级结构（产品类型）的具的体产品。 
  举例：Linux的具体产品类型包括Linux手机版和Linux PC版，Windows的具体产品类型包括Windows手机版和Windows PC版。 
  产品族和产品等级的关系： 
 
要点： 
1.抽象工厂应用场景： 
  一个系统要独立于它的产品的创建、组合和表示时。 
  一个系统要由多个产品系列中的一个来配置时。 
  当你要强调一系列相关的产品对象的设计以便进行联合使用时。 
  当你提供一个产品类库，而只想显示它们的接口而不是实现时。 
2.新增产品复杂。抽象工厂增加产品组件时，需要更改所有工厂的接口。如增加产品ProductC，则工厂基类和具体工厂需要增加接口CreateProductC。 
3. 抽象工厂模式与工厂方法模式的区别。 
    a．重点不同。工厂方法模式强调的是不同的创建者根据自身需求去生产不同的具体产品，重点是生产具体产品；而抽象工厂模式则定位为 
      “在不指定实体类别的前提下，提供了一个可以创建一系列相关或互相依赖之组件的接口”，重点是创建相关组件。 
    b．抽象工厂提供了的“相关组件”可以看成是具体的产品（如ProductA1），抽象工厂模式的“相关组件”可由工厂模式实现。 
       ConcreteFactory1.CreateProuductA()生产的具体产品，可以用工厂方法模式实现，即每一个产品用一个工厂方法实现。 
    c．工厂方法模式只有一个抽象产品类，而抽象工厂模式有多个。工厂方法模式的具体工厂类只能创建一个具体产品类的实例， 
       而抽象工厂模式可以创建多个。 
    d. 抽象工厂不能直接创建产品，只能创建工厂，即抽象工厂创建的产品是工厂。虽然它也定义了创建产品的方法，但需要创建出来的 
       具体的工厂实现，即抽象工厂创建出的工厂创建产品。 
    e．工厂方法采用的是类继承机制（生成一个子类，重写该工厂方法，在该方法中生产一个对象）；而抽象工厂采用的是对象组合机制， 
       专门定义“工厂”对象来负责对象的创建。对象组合的方式就是把“工厂”对象作为参数传递。 
 
应用： 
1.抽象工厂模式可应用：支持多种数据库的数据库接口访问层；界面设计各种风格界面等。 
2.源码中通过PC工厂和手机工厂和预装的操作系统产品来举例实现模式。 
 
以上文字说明，从网上整理而来，有可能部分与其他同仁相同，请谅解，希望我们能够共同交流，谢谢！ 
*/  
int main(){
    AbstractFactory* abstractFactory = new MobileFactory;
    Linux* linux = abstractFactory->createLinux();
    Windows* windows = abstractFactory->createWindows();
    linux->create();
    windows->create();
    cout<<endl;
    
    abstractFactory = new PCFactory;
    linux = abstractFactory->createLinux();
    windows = abstractFactory->createWindows();
    linux->create();
    windows->create();
    
    system("pause");
    return 0;
}
