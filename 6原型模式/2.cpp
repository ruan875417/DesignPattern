//原型模式：用原型实例指定创建对象的种类，
//并且通过拷贝这些原型创建新的对象
//c++的原型模式借助拷贝构造函数实现,对象的构造不是通过构造函数，
//而是通过一个clone函数完成，而这个函数中调用拷贝构造函数，实现自身的拷贝

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//原型基类
class ICloneable
{
protected:
	virtual ICloneable* Clone() = 0;
};

//具体原型类
class WorkExperience : public ICloneable
{
public:
	WorkExperience() : workDate(""), company("")
	{

	}

	WorkExperience(string _workDate, string _company) 
		: workDate(_workDate), company(_company)
	{

	}

	WorkExperience(const WorkExperience& object)
	{
        workDate = object.workDate;
		company = object.company;
	}

	ICloneable* Clone()
	{
		cout << "clone一个WorkExperience" << endl;
		//调用拷贝构造函数实现clone
		return new WorkExperience(*this);
	}

//private:
	string workDate;
	string company;
};

//原型具体类
class Resume : public ICloneable
{
public:
	Resume(string _name) : name(_name), sex(""), age(0), work(new WorkExperience)
	{
       
	}

	Resume(const Resume& object)
	{
		work = (WorkExperience*)(object.work->Clone());
		name = object.name;
		sex = object.sex;
		age = object.age;
	}
	
	~Resume()
	{
		delete work;
		work = NULL;
	}

	//设置个人信息
	void SetPersonalInfo(string _sex, int _age)
	{
        sex = _sex;
		age = _age;
	}

	//设置个人经历
	void  SetWorkExperience(string _workdate, string _company)
	{
		work->workDate = _workdate;
		work->company = _company;
	}

	ICloneable* Clone()
	{
        cout << "\nclone一份简历...." << endl;
		return new Resume(*this);
	}

	void Display()
	{
		cout << name << " " << sex << " " << age << endl;
		cout << "工作经历： " << work->workDate << " " << work->company << endl;
	}

private:
    string name;
	string sex;
	int age;
	WorkExperience *work;
};

int main()
{
	Resume *a = new Resume("大鸟");
	a->SetPersonalInfo("男", 29);
	a->SetWorkExperience("1999-2000", "XX公司");
	a->Display();

	//运用clone加更改
	Resume *b = (Resume*)(a->Clone());
	b->SetWorkExperience("1998-2006", "YY企业");
    b->Display();

	Resume *c = (Resume*)a->Clone();
	c->SetPersonalInfo("女", 23);
	c->SetWorkExperience("1998-2003", "ZZ企业");
    c->Display();

    delete a;
	a = NULL;
	delete b;
	b = NULL;
	delete c;
	c = NULL;

	system("pause");
	return 0;
}
