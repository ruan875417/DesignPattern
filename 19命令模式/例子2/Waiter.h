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
          if(command->getName()=="烤鸡翅"){ 
             cout<<"服务员：鸡翅没了，请点别的烧烤"<<endl; 
          }else{
             orders.push_back(command);
          }
      } 
      void cancelOrder(Command* command){
          vector<Command*>::iterator it;
          for(it=orders.begin();it!=orders.end();it++){
              if(*it==command){
                  orders.erase(it);
                  cout<<(*it)->getName()<<"取消"<<endl;
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
