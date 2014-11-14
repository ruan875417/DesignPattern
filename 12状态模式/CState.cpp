#include "CState.h"

void EveningState::work(CWork* work){
     if(work->getTime()<23)
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",���ڿ�����"<<endl;
     else{
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",����˯��"<<endl;
     }
}; 
void TowardEveningState::work(CWork* work){
     if(work->getTime()<19)
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",���ڳ���"<<endl;
     else{
        work->setState(new EveningState);
        work->work();
     }
}; 
void AfternoonState::work(CWork* work){
     if(work->getTime()<17)
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",������ϰ���ģʽ"<<endl;
     else{
        work->setState(new TowardEveningState);
        work->work();
     }
}; 
void NoonState::work(CWork* work){
     if(work->getTime()<13)
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",���ڳ��緹����˯"<<endl;
     else{
        work->setState(new AfternoonState);
        work->work();
     }
}; 
void ForenoonState::work(CWork* work){
     if(work->getTime()<11)
        cout<<"��ǰʱ���ǣ�"<<work->getTime()<<",������ϰ�㷨��c++"<<endl;
     else{
        work->setState(new NoonState);
        work->work();
     }
};
