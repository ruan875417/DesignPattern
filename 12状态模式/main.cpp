#include <iostream>
#include "CWork.h"
#include "CState.h" 
using namespace std;

int main(){
    CWork* work=new CWork;
    work->setState(new ForenoonState);
    work->setTime(9);
    work->work();
    
    work->setTime(12);
    work->work();
    work->setTime(15);
    work->work();
    work->setTime(18);
    work->work();
    work->setTime(22);
    work->work();
    work->setTime(24);
    work->work();
    
    system("pause");
    return 0;
}
