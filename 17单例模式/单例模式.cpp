#include<iostream>
using namespace std;
/********************************************** 
* 单例模式原理： 
*   保证一个类仅有一个实例，并提供一个访问它的全 
* 局访问点。 
*   通常我们可以让一个全局变量使得一个对象被访问,
* 但它不能防止你实例化多个对象。一个最好的办 
* 法是让类自身负责保存它的唯一实例。这个类可以保 
* 证没有其它实例可以被创建，并且它可以提供一个访 
* 问该实例的方法。 

* 总结： 
*   虽然说单例模式比较简单、应用比较广泛，但是在考虑的时候，细节还是很 
* 多的。目前如果使用静态的成员变量指针，存在的问题是，何时去释放？如何 
* 通知其它地方已经被释放？还有如何防止CSingleton类被其它类继承的问题？ 
* 这些都比较纠结？谁能给个解决方法，谢谢了~~~ 
************************************************************************/  
// Singleton类  
//   定义一个GetInstance操作，允许客户访问它的唯  
// 一实例。GetInstance 是静态方法，主要负责创建  
// 自己的唯一实例  
class Singleton{
   private:
      static Singleton* instance;
      // 构造方法为私有，阻止外界利用new创建此类实例的可能  
      Singleton(){};
   public:
      // 若实例不存在则创建一个实例，否则返回已有的实例  
      static Singleton* getInstance(){
         // if(instance==NULL){
            // lock();
                if(instance==NULL){
                   instance =new Singleton;
                }
            //unlock(); 
          //}
          return instance;
      }
      static void release(){
          if(instance!=NULL){
             delete instance;
             instance=NULL;
          }
      }
};
Singleton* Singleton::instance=NULL;
int main(){   
    Singleton* s1=Singleton::getInstance();
    Singleton* s2=Singleton::getInstance();
    s2->release();
    if(s1==s2)
       cout<<"两个对象是相同的实例"<<endl;
    system("pause");
    return 0;
}
