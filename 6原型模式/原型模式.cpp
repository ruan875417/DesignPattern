#include<iostream>
#include<string>
using namespace std;
/*ԭ��ģʽ����ԭ��ʵ��ָ��������������࣬  
  ����ͨ��������Щԭ�ʹ����µĶ���  
  c++��ԭ��ģʽ�����������캯��ʵ��,����Ĺ��첻��ͨ�����캯����  
  ����ͨ��һ��clone������ɣ�����������е��ÿ������캯����ʵ������Ŀ���*/
/*ԭ�ͻ���*/
class Prototype{
    public:
      Prototype(){}
      virtual Prototype* clone()=0;
};
/*����ԭ����*/ 
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
           //���ÿ������캯��ʵ��clone  
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
           //���ÿ������캯��ʵ��clone  
           return new Resume(*this);
       }  
       void display(){
           cout<<name<<"  "<<sex<<"  "<<age<<endl;
           cout<<work->getWorkDate()<<"  "<<work->getCompany()<<endl;
       }             
};
int main(){
    Resume* daniao=new Resume("daniao","male","30");
    daniao->setWorkExperience("1999-2000","xx��˾");
    daniao->display();
    
    Resume* xiaocai=(Resume*)(daniao->clone());
    xiaocai->setName("xiaocai");
    xiaocai->setAge("24");
    xiaocai->setWorkExperience("2004-2005","YY��˾");
    xiaocai->display();
    
    delete daniao;
    daniao=NULL;
    delete xiaocai; 
    xiaocai=NULL;
    
    system("pause");
    return 0;
}
