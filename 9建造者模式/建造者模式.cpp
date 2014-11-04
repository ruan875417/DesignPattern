#include<iostream>
#include<vector>
using namespace std;
/////////////////////////////////////
/********************************************** 
* ������ģʽԭ��[������ģʽ] 
*   ��һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ 
* ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ�� 
*   �������ʹ���˴�����ģʽ����ô�û���ֻ 
* ��Ҫ��������;Ϳ��Եõ����ǣ������彨�� 
* �Ĺ��̺�ϸ�ھͲ���Ҫ֪���ˡ� 
***********************************************/  
/************************************************************************ 
* С�᣺ 
*   1��������ģʽ��Ҫ���ڴ���һЩ���ӵĶ�����Щ�����Ľ���˳��ͨ 
*      �����ȶ��ģ��������ڲ��Ĺ���ͨ�������Ÿ��ӵı仯�� 
*   2��������ģʽ�ĺô�����ʹ�ý���������ʾ������룬���ڽ������� 
*      ���˸ò�Ʒ�������װ�ģ���������Ҫ�ı�һ����Ʒ�ڲ���ʾ��ֻ�� 
*      Ҫ�ٶ���һ������Ľ����߾Ϳ����ˡ� 
*   3��������ģʽ���ڵ��������Ӷ�����㷨Ӧ�ö����ڸö������ɲ��� 
*      �Լ����ǵ�װ�䷽ʽʱ���õ�ģʽ�� 
************************************************************************/ 
// �����Ʒ��  
//      һ����Ʒ�ɶ��������ɡ�  
class Product{
    private:
       vector<string> part;
    public:
       void add(string part){ this->part.push_back(part); }
       void show(){
           cout<<"��Ʒ����"<<endl;
           vector<string>::iterator it;
           for(it=part.begin();it!=part.end();++it)
           {
               cout<<"����:"<<*it<<endl;                                   
           } 
       }
};
// ����������  
//    Ϊ����һ��Product����ĸ�������ָ���ĳ���ӿڡ�  
class Build{
    public:
       virtual void buildPartA(){}
       virtual void buildPartB(){}
       virtual Product* getResult(){ return NULL; }
};
// ���彨������  
//    ʵ��Builder�ӿڣ������װ�����������  
class ConcreteBuild1:public Build{
    private:
       Product* product;
    public:
       ConcreteBuild1(){ product=new Product; }
       void buildPartA(){ product->add("����1"); }
       void buildPartB(){ product->add("����2"); }
       Product* getResult(){ return product; }
       ~ConcreteBuild1(){
            if(product!=NULL){
               delete product;
               product=NULL;
            }
       } 
};
class ConcreteBuild2:public Build{
    private:
       Product* product;
    public:
       ConcreteBuild2(){ product=new Product; }
       void buildPartA(){ product->add("����A"); }
       void buildPartB(){ product->add("����B"); }
       Product* getResult(){ return product; }
       ~ConcreteBuild2(){
            if(product!=NULL){
               delete product;
               product=NULL;
            }
       }
};
// ָ������  
//    ����һ��ʹ��Builder�ӿڵĶ��� 
class Director{
   public:
      void construct(Build* build){
         build->buildPartA();
         build->buildPartB();
      }
};
int main(){
    Director* director=new Director;
    Build* build1=new ConcreteBuild1;
    director->construct(build1);
    Product* product1=build1->getResult();
    product1->show();
    
    Build* build2=new ConcreteBuild2;
    director->construct(build2);
    Product* product2=build2->getResult();
    product2->show();
    
    system("pause");
    return 0;
}
