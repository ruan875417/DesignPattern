#include<iostream>
using namespace std;
/********************************************** 
* ����ģʽԭ�� 
*   ��֤һ�������һ��ʵ�������ṩһ����������ȫ 
* �ַ��ʵ㡣 
*   ͨ�����ǿ�����һ��ȫ�ֱ���ʹ��һ�����󱻷���,
* �������ܷ�ֹ��ʵ�����������һ����õİ� 
* �������������𱣴�����Ψһʵ�����������Ա� 
* ֤û������ʵ�����Ա������������������ṩһ���� 
* �ʸ�ʵ���ķ����� 

* �ܽ᣺ 
*   ��Ȼ˵����ģʽ�Ƚϼ򵥡�Ӧ�ñȽϹ㷺�������ڿ��ǵ�ʱ��ϸ�ڻ��Ǻ� 
* ��ġ�Ŀǰ���ʹ�þ�̬�ĳ�Ա����ָ�룬���ڵ������ǣ���ʱȥ�ͷţ���� 
* ֪ͨ�����ط��Ѿ����ͷţ�������η�ֹCSingleton�౻������̳е����⣿ 
* ��Щ���ȽϾ��᣿˭�ܸ������������лл��~~~ 
************************************************************************/  
// Singleton��  
//   ����һ��GetInstance����������ͻ���������Ψ  
// һʵ����GetInstance �Ǿ�̬��������Ҫ���𴴽�  
// �Լ���Ψһʵ��  
class Singleton{
   private:
      static Singleton* instance;
      // ���췽��Ϊ˽�У���ֹ�������new��������ʵ���Ŀ���  
      Singleton(){};
   public:
      // ��ʵ���������򴴽�һ��ʵ�������򷵻����е�ʵ��  
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
       cout<<"������������ͬ��ʵ��"<<endl;
    system("pause");
    return 0;
}
