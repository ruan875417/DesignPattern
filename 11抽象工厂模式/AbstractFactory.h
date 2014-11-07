#ifndef ABSTTACTFACTORY_H
#define ABSTTACTFACTORY_H

#include<iostream>
using namespace std;
//////////////////////////////////////////
//抽象产品类A，  
//定义了具体产品类A统一的接口  
class Linux{
    public:
       virtual void create()=0;         
}; 
//抽象产品类B  
//定义了具体产品类B统一的接口  
class Windows{
    public:
       virtual void create()=0;
};
///////////////////////////////////////////
//具体产品  
class LinuxMobile:public Linux{
    public:
       void create();
};
class LinuxPC:public Linux{
    public:
       void create();
};
class WindowsMobile:public Windows{
    public:
       void create();
};
class WindowsPC:public Windows{
    public:
       void create();
};
//////////////////////////////////////////////////
//抽象工厂，它里面应该包含  
//所有产品创建的抽象方法  
class AbstractFactory{
    public:
       virtual Linux* createLinux()=0;
       virtual Windows* createWindows()=0;
};
//具体工厂，创建具有特定  
//实现的产品对象  
class MobileFactory:public AbstractFactory{
    public:
        Linux* createLinux();
        Windows* createWindows();
};
class PCFactory:public AbstractFactory{
    public:
        Linux* createLinux();
        Windows* createWindows();
};

#endif
