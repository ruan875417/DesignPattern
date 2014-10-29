#include<iostream>
#include<string>
using namespace std;
/*原型模式：用原型实例指定创建对象的种类，  
  并且通过拷贝这些原型创建新的对象  
  c++的原型模式借助拷贝构造函数实现,对象的构造不是通过构造函数，  
  而是通过一个clone函数完成，而这个函数中调用拷贝构造函数，实现自身的拷贝*/
/*原型基类*/
class Prototype{
    public:
      Prototype(){}
      virtual Prototype* clone()=0;
};
/*具体原型类*/ 
class WorkExperience:public Prototype{
    private:
       string workDate;
       string company;
    public:
       WorkExperience(){}
       WorkExperience(string workDate,string company){ 
           this->workDate=workDate; 
           this->company=company;
       }
       string getWorkDate(){ return workDate; }
       string getCompany(){ return company;}
       void setWorkDate(string workDate){ this->workDate=workDate; }
       void setCompany(string company){ this->company=company;}
       WorkExperience(const WorkExperience& we){ 
           workDate=we.workDate; 
           company=we.company;
       }  
       Prototype* clone()
       {
           cout<<"clone WorkExperience"<<endl;
           //调用拷贝构造函数实现clone  
           return new WorkExperience(*this);
       }               
};
class Resume:public Prototype{
    private:
       WorkExperience* work;
       string name;
       string sex;
       string age;
    public:
       Resume(){}
       Resume(string name,string sex,string age){
          this->name = name;
          this->sex = sex;
          this->age = age;
          work=new WorkExperience;
       }
       Resume(const Resume& rs){
           work=(WorkExperience*)(rs.work->clone()); 
           name=rs.name; 
           sex=rs.sex;
           age=rs.age;   
       }
       void setName(string name){ this->name = name; }
       void setSex(string sex){ this->sex = sex; }
       void setAge(string age){ this->age = age; }
       void setWorkExperience(string workDate,string company)
       {
            work->setWorkDate(workDate);
            work->setCompany(company);
       }
       Prototype* clone()
       {
           cout<<"clone Resume"<<endl;
           //调用拷贝构造函数实现clone  
           return new Resume(*this);
       }  
       void display(){
           cout<<name<<"  "<<sex<<"  "<<age<<endl;
           cout<<work->getWorkDate()<<"  "<<work->getCompany()<<endl;
       }             
};
int main(){
    Resume* daniao=new Resume("daniao","male","30");
    daniao->setWorkExperience("1999-2000","xx公司");
    daniao->display();
    
    Resume* xiaocai=(Resume*)(daniao->clone());
    xiaocai->setName("xiaocai");
    xiaocai->setAge("24");
    xiaocai->setWorkExperience("2004-2005","YY公司");
    xiaocai->display();
    
    delete daniao;
    daniao=NULL;
    delete xiaocai; 
    xiaocai=NULL;
    
    system("pause");
    return 0;
}
