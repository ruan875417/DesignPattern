#ifndef WAITER_H
#define WAITER_H
#include "Command.h"

class Waiter{
   private:
      Command* command;
   public:
      Waiter(){}
      void setOrder(Command* command){
          this->command=command;
      }
      void notify(){
          command->excuteCommand();
      }
};

#endif
