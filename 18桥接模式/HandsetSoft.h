#ifndef HANDSETSOFT_H
#define HNADSETSOFT_H
#include<iostream>
using namespace std;

class HandsetSoft{
    public:
        virtual void run()=0;  
};
class HandsetGame:public HandsetSoft{
    public:
        void run(){
             cout<<"�����ֻ����"<<endl;
        }
};
class HandsetAddressList:public HandsetSoft{
    public:
        void run(){
             cout<<"�����ֻ�ͨѶ¼"<<endl;
        }
};

#endif
