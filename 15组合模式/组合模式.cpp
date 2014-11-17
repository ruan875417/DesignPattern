#include<iostream>
#include<list> 
using namespace std;
//�����࣬�û�ͨ���ýӿ����������Ӳ���  
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
class Leaf:public Component{//���Ҷ�ӽڵ� 
   public:
      Leaf(string name):Component(name){}
      void add(Component* c){ cout<<"������Ҷ�ӽڵ���Ӳ���"<<endl; }
      void remove(Component* c){ cout<<"������Ҷ�ӽڵ�ɾ������"<<endl; }
      void display(int depth){ cout<<string(depth,'-')<<name<<endl; }
};
class Composite:public Component{//��ӷ�֧��㣨����Ҷ�ӽ�㣩
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
