#include "Person.h"
#include "Action.h"
Man::Man(string sex){ this->sex=sex;}
string Man::getSex(){ return sex; }
void Man::accept(Action* visitor){
    visitor->getManConclusion(this);
}

Woman::Woman(string sex){ this->sex=sex;}
string Woman::getSex(){ return sex; }
void Woman::accept(Action* visitor){
     visitor->getWomanConclusion(this);
}
