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
/*Decarate��*/
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
/*ConcreteDecarate��*/
class TShirts:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear TShirts"<<"    ";
       }
};
/*ConcreteDecarate��*/
class Coats:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear Coats"<<"    ";
       }
};
/*ConcreteDecarate��*/
class Sneaker:public Finery{
    public:
       void show()
       {
            Finery::show();
            cout<<"wear Sneaker"<<"    ";
       }
};
/*�ͻ���*/
int main(){
    Person person("xiaocai");
    TShirts shirt;
    Coats coats;
    Sneaker sneaker;
    
    shirt.decorate(&person);
    coats.decorate(&shirt);
    sneaker.decorate(&coats);
    
    cout<<"��һ��װ��"<<endl;
    coats.show();
    
    cout<<endl<<"�ڶ���װ��"<<endl;
    sneaker.show();
    
    system("pause");
    return 0;
}
