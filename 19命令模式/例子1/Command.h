#ifndef COMMAND_H
#define COMMAND_H
#include "Barbecuer.h"

class Command{
    protected:
        Barbecuer* barbecuer;
    public:
        Command(Barbecuer* barbecuer){
            this->barbecuer=barbecuer;
        }
        virtual void excuteCommand()=0;
};
class BakeChickenWingCommand:public Command{
    public:
       BakeChickenWingCommand(Barbecuer* barbecuer):Command(barbecuer){}
       void excuteCommand(){
            barbecuer->bakeChickenWing();
       }
};
class BakeMuttonCommand:public Command{
    public:
       BakeMuttonCommand(Barbecuer* barbecuer):Command(barbecuer){}
       void excuteCommand(){
            barbecuer->bakeMutton();
       }
};
#endif
