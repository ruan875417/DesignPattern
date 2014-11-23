#ifndef INVOKER_H
#define INVOKER_H
#include "Command.h"

class Invoker{
   private:
      Command* command;
   public:
      void setCommand(Command* command){
          this->command=command;
      }
      void excuteCommand(){
          command->excute();
      }
};

#endif 
