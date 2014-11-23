#ifndef WAITER_H
#define WAITER_H
#include<vector>
#include "Command.h"

class Waiter{
   private:
      vector<Command*> orders;
   public:
      Waiter(){}
      void setOrder(Command* command){
          if(command->getName()=="������"){ 
             cout<<"����Ա������û�ˣ�������տ�"<<endl; 
          }else{
             orders.push_back(command);
          }
      } 
      void cancelOrder(Command* command){
          vector<Command*>::iterator it;
          for(it=orders.begin();it!=orders.end();it++){
              if(*it==command){
                  orders.erase(it);
                  cout<<(*it)->getName()<<"ȡ��"<<endl;
              }
          }
      }
      void notify(){
          vector<Command*>::iterator it;
          for(it=orders.begin();it!=orders.end();it++){
              (*it)->excuteCommand();
          }
      }
};

#endif
