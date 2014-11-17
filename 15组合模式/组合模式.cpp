#include<iostream>
#include<list> 
using namespace std;
//抽象类，用户通过该接口来访问其子部件  
class Component{
   protected:
      string name;
   public:
      Component(){}
      Component(string name){ this->name=name; }
      virtual void add(Component* c)=0;
      virtual void remove(Component* c)=0;
      virtual void display(int depth)=0;
};
class Leaf:public Component{//添加叶子节点 
   public:
      Leaf(string name):Component(name){}
      void add(Component* c){ cout<<"不能向叶子节点添加部件"<<endl; }
      void remove(Component* c){ cout<<"不能向叶子节点删除部件"<<endl; }
      void display(int depth){ cout<<string(depth,'-')<<name<<endl; }
};
class Composite:public Component{//添加分支结点（即非叶子结点）
   private:
      list<Component*> child;
   public:
      Composite(string name):Component(name){}
      void add(Component* c){ child.push_back(c); }
      void remove(Component* c){ child.remove(c); }
      void display(int depth){
          cout<<string(depth,'-')<<name<<endl; 
          list<Component*>::iterator it=child.begin();
          while(it!=child.end()){
              (*it)->display(depth+1);
              it++;               
          }
      }
};
int main(){
    Composite root("root");
    
    Leaf* leafa=new Leaf("Leaf A");
    root.add(leafa); 
    
    Leaf* leafb=new Leaf("Leaf B");
    root.add(leafb); 
    
    Composite* comp1=new Composite("Composite X");
    root.add(comp1); 
    
    Composite* comp2=new Composite("Composite XY");
    comp1->add(comp2);
    
    Leaf* leafxya=new Leaf("Leaf XYA");
    comp2->add(leafxya);
    
    Leaf* leafxyb=new Leaf("Leaf XYB");
    comp2->add(leafxyb);
    
    Leaf* leafc=new Leaf("Leaf C");
    root.add(leafc); 
    
    Leaf* leafd=new Leaf("Leaf D");
    root.add(leafd); 
    root.display(1);
    
    system("pause");
    return 0;
}
