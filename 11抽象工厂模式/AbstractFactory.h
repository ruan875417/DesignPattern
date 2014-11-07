#ifndef ABSTTACTFACTORY_H
#define ABSTTACTFACTORY_H

#include<iostream>
using namespace std;
//////////////////////////////////////////
//�����Ʒ��A��  
//�����˾����Ʒ��Aͳһ�Ľӿ�  
class Linux{
    public:
       virtual void create()=0;         
}; 
//�����Ʒ��B  
//�����˾����Ʒ��Bͳһ�Ľӿ�  
class Windows{
    public:
       virtual void create()=0;
};
///////////////////////////////////////////
//�����Ʒ  
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
//���󹤳���������Ӧ�ð���  
//���в�Ʒ�����ĳ��󷽷�  
class AbstractFactory{
    public:
       virtual Linux* createLinux()=0;
       virtual Windows* createWindows()=0;
};
//���幤�������������ض�  
//ʵ�ֵĲ�Ʒ����  
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
