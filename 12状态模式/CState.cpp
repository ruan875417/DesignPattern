#include "CState.h"

void EveningState::work(CWork* work){
     if(work->getTime()<23)
        cout<<"当前时间是："<<work->getTime()<<",正在看电视"<<endl;
     else{
        cout<<"当前时间是："<<work->getTime()<<",正在睡觉"<<endl;
     }
}; 
void TowardEveningState::work(CWork* work){
     if(work->getTime()<19)
        cout<<"当前时间是："<<work->getTime()<<",正在吃晚饭"<<endl;
     else{
        work->setState(new EveningState);
        work->work();
     }
}; 
void AfternoonState::work(CWork* work){
     if(work->getTime()<17)
        cout<<"当前时间是："<<work->getTime()<<",正在练习设计模式"<<endl;
     else{
        work->setState(new TowardEveningState);
        work->work();
     }
}; 
void NoonState::work(CWork* work){
     if(work->getTime()<13)
        cout<<"当前时间是："<<work->getTime()<<",正在吃午饭或午睡"<<endl;
     else{
        work->setState(new AfternoonState);
        work->work();
     }
}; 
void ForenoonState::work(CWork* work){
     if(work->getTime()<11)
        cout<<"当前时间是："<<work->getTime()<<",正在练习算法和c++"<<endl;
     else{
        work->setState(new NoonState);
        work->work();
     }
};
