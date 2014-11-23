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
        virtual string getName()=0;
};
class BakeChickenWingCommand:public Command{
    private:
       string name;
    public:
       BakeChickenWingCommand(Barbecuer* barbecuer):Command(barbecuer){
           name="¿¾¼¦³á";
       }
       void excuteCommand(){
            barbecuer->bakeChickenWing();
       }
       string getName(){ return name; }
};
class BakeMuttonCommand:public Command{
    private:
       string name;
    public:
       BakeMuttonCommand(Barbecuer* barbecuer):Command(barbecuer){
           name="¿¾ÑòÈâ´®";
       }
       void excuteCommand(){
            barbecuer->bakeMutton();
       }
       string getName(){ return name; }
};
#endif
