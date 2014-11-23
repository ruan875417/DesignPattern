#include<iostream>
using namespace std;
/* 
    ְ����ģʽ�������������ߺͽ����������һ���ö�������л��ᴦ�����󣬽���Щ�������Ӵ�һ���������� 
    ������������������ֱ���ж�������Ϊֹ��  
    ����������¿���ʹ��ְ����ģʽ�� 
    (1)�ж��������Դ���ͬһ�����󣬾����ĸ������������������ʱ���Զ�ȷ���� 
    (2)�ڲ���ȷָ�������ߵ�����£����������е�һ���ύһ������ 
    (3)�ɶ�ָ̬��һ����������� 
    Ӧ�þ����� 
        �������ڱ�����if..else��֧�ṹ 
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
