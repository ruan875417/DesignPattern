#include<iostream>
using namespace std;
/////////////////////////////////////////////////////// 
class Singleton{
   private:
      static Singleton instance;
      Singleton(){};
   public:
      static Singleton* getInstance(){
          return &instance;
      }
   
};
Singleton Singleton::instance;
int main(){   
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();    
    if(s1==s2)
       cout<<"两个对象是相同的实例"<<endl;
    system("pause");
    return 0;
}
