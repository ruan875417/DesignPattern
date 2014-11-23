#ifndef COMMAND_H
#define COMMAND_H
#include "Receiver.h"

class Command{
    protected:
        Receiver* receiver;
    public:
        Command(Receiver* receiver){
            this->receiver=receiver;
        }
        virtual void excute()=0;
};
class ConcreteCommand:public Command{
    public:
       ConcreteCommand(Receiver* receiver):Command(receiver){}
       void excute(){
            receiver->action();
       }
};
      
#endif
