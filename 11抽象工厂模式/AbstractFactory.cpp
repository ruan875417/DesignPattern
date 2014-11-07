#include "AbstractFactory.h"

void LinuxMobile::create(){
     cout<<"create Linux Mobile"<<endl;
}
void LinuxPC::create(){
     cout<<"create Linux PC"<<endl;
}
void WindowsMobile::create(){
     cout<<"create Windows Mobile"<<endl;
}
void WindowsPC::create(){
     cout<<"create Windows PC"<<endl;
}

Linux* MobileFactory::createLinux(){
    return new LinuxMobile;
}
Windows* MobileFactory::createWindows(){
    return new WindowsMobile;
}
Linux* PCFactory::createLinux(){
    return new LinuxPC;
}
Windows* PCFactory::createWindows(){
    return new WindowsPC;
}
     
