#include "Action.h"
#include "Person.h"
#include<list>
class ObjectStructure{
   private:
      list<Person*> personlist;
   public:
      void attach(Person* person){
         personlist.push_back(person);
      }    
      void detach(Person* person){
         personlist.remove(person);
      }    
      void display(Action* visitor){
         list<Person*>::iterator it;
         for(it=personlist.begin();it!=personlist.end();it++){
             (*it)->accept(visitor);
         }
      }
};
int main(){
    ObjectStructure* objectStructure=new ObjectStructure;
    objectStructure->attach(new Man("ÄÐÈË"));
    objectStructure->attach(new Woman("Å®ÈË"));
    
    Success* success=new Success;
    objectStructure->display(success);
    
    Failing* failing=new Failing;
    objectStructure->display(failing);
    
    Loving* loving=new Loving;
    objectStructure->display(loving);
    
    delete loving;
    delete failing;
    delete success;
    delete objectStructure;
    
    system("pause");
    return 0;
}
