/********************************************** 
* 适配器模式原理： 
*   将一个类的接口转换成客户希望的另外一个 
* 接口。适配器模式使得原本由于原本接口不兼 
* 容而不能一起工作的那些类可以一起工作。 

* 小结： 
*   1、系统的数据和行为都正确，但接口不符合时我们应该考虑适配器，目 
*      的是使控制范围之外的一个原有对象与某个接口匹配。适配器模式主 
*      要应用于希望复用一些现存的类，但是接口又与复用环境要求不一致 
*      的情况。 
*   2、使用一个已经存在的类，但如果它的接口，也就是它的方法和你的要 
*      求不同时，就应该考虑使用适配器模式。 
*   3、两个类做的事情相同或相似，但是具有不同的接口时要是用它。 
*   4、客户代码可以统一调用同一接口，可以更简单、更直接、更紧凑。 
*   5、双方都不太容易修改的时候再使用适配器模式适配。 
************************************************************************/  
#include<iostream>
using namespace std;
///////////////////////////////////
// 目标接口类  
//   客户所期待的借口，目标可以是具体的或抽  
// 象的类，也可以是接口。  
class Target{
    public:
       virtual void request(){
           cout<<"普通请求"<<endl;
       }
};
// 需要适配类  
class Adaptee{
    public:
       void specificrequest(){
           cout<<"特殊请求"<<endl;
       }
};
// 适配器类  
//   通过在内部包装一个CAdaptee对象，把原接  
// 口转换成目标接口。  
class Adapter:public Target{
    private:
       Adaptee* adaptee;
    public:
       Adapter(){ adaptee=new Adaptee; };
       void request(){
            adaptee->specificrequest();
       }
};
int main(){
    Target* target=new Adapter;
    target->request();
    
    system("pause");
    return 0;
}
