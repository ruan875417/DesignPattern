#include "Waiter.h"

int main(){
   Barbecuer* barbecuer=new Barbecuer;
   Command* bakeChickenWingCommand1=new BakeChickenWingCommand(barbecuer);
   Command* bakeChickenWingCommand2=new BakeChickenWingCommand(barbecuer);
   Command* bakeMuttonCommand1=new BakeMuttonCommand(barbecuer);
   
   Waiter* waiter=new Waiter;
   waiter->setOrder(bakeChickenWingCommand1);
   waiter->notify();
   waiter->setOrder(bakeChickenWingCommand2);
   waiter->notify();
   waiter->setOrder(bakeMuttonCommand1);
   waiter->notify();
   
   system("pause");
   return 0;
}
