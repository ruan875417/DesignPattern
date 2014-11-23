#include<iostream>
using namespace std;
/* 
    职责链模式：避免请求发送者和接受者耦合在一起，让多个对象都有机会处理请求，将这些对象连接处一条链，并且 
    沿着这条链传递请求，直到有对象处理它为止。  
    在以下情况下可以使用职责链模式： 
    (1)有多个对象可以处理同一个请求，具体哪个对象处理该请求由运行时刻自动确定。 
    (2)在不明确指定接收者的情况下，向多个对象中的一个提交一个请求。 
    (3)可动态指定一组对象处理请求。 
    应用举例： 
        可以用于避免多个if..else分支结构 
*/  
class Handler{
    protected:
        Handler* successor;
    public:
        void setSuccessor(Handler* successor){
             this->successor=successor;
        }
        virtual void handleRequest(int request)=0;
};
class concreteHander1:public Handler{
    public:
        void handleRequest(int request){
           if(request==1){
               cout<<"handler1 can handle"<<endl;
           } else if(successor!=NULL){
               cout<<"handler1 can't handle"<<endl;
               successor->handleRequest(request);
           } 
        }         
};
class concreteHander2:public Handler{
    public:
        void handleRequest(int request){
           if(request==2){
               cout<<"handler2 can handle"<<endl;
           } else if(successor!=NULL){
               cout<<"handler2 can't handle"<<endl;
               successor->handleRequest(request);
           }  
        }        
};
class concreteHander3:public Handler{
    public:
        void handleRequest(int request){
           if(request==3){
               cout<<"handler3 can handle"<<endl;
           } else if(successor==NULL){
               cout<<"no handler can handle"<<endl;
           }   
        }       
};
int main(){
     Handler* handler1=new concreteHander1;
     Handler* handler2=new concreteHander2;
     Handler* handler3=new concreteHander3;
     
     handler1->setSuccessor(handler2);
     handler2->setSuccessor(handler3);
     handler3->setSuccessor(NULL);
     
     handler1->handleRequest(1);
     cout<<endl; 
     
     handler1->handleRequest(2);
     cout<<endl; 
     
     handler1->handleRequest(3);
     cout<<endl; 
     
     handler1->handleRequest(4);
     cout<<endl; 
     
     system("pause");
     return 0;
}
