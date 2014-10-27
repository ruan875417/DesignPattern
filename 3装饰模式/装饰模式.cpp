#include<iostream>
#include<string> 
using namespace std;
//////////////////////////////////////////////////////////
/*Component*/
class Person{
    private:
       string name;
    public:
       Person(){}
       Person(string name){ this->name=name; }
       virtual void show(){ cout<<name<<"    "; }
};
/*Decarate类*/
class Finery:public Person{
    protected:
       Person* component;
    public:
       void decorate(Person* component){ this->component=component; }
       virtual void show(){
           if(component!=NULL)
              component->show(); 
       } 
};
/*ConcreteDecarate类*/
class TShirts:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear TShirts"<<"    ";
       }
};
/*ConcreteDecarate类*/
class Coats:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear Coats"<<"    ";
       }
};
/*ConcreteDecarate类*/
class Sneaker:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear Sneaker"<<"    ";
       }
};
/*客户端*/
int main(){
    Person person("xiaocai");
    TShirts shirt;
    Coats coats;
    Sneaker sneaker;
    
    shirt.decorate(&person);
    coats.decorate(&shirt);
    sneaker.decorate(&coats);
    
    cout<<"第一种装扮"<<endl;
    coats.show();
    
    cout<<endl<<"第二种装扮"<<endl;
    sneaker.show();
    
    system("pause");
    return 0;
}
