//ԭ��ģʽ����ԭ��ʵ��ָ��������������࣬
//����ͨ��������Щԭ�ʹ����µĶ���
//c++��ԭ��ģʽ�����������캯��ʵ��,����Ĺ��첻��ͨ�����캯����
//����ͨ��һ��clone������ɣ�����������е��ÿ������캯����ʵ������Ŀ���

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//ԭ�ͻ���
class ICloneable
{
protected:
	virtual ICloneable* Clone() = 0;
};

//����ԭ����
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
		cout << "cloneһ��WorkExperience" << endl;
		//���ÿ������캯��ʵ��clone
		return new WorkExperience(*this);
	}

//private:
	string workDate;
	string company;
};

//ԭ�;�����
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

	//���ø�����Ϣ
	void SetPersonalInfo(string _sex, int _age)
	{
        sex = _sex;
		age = _age;
	}

	//���ø��˾���
	void  SetWorkExperience(string _workdate, string _company)
	{
		work->workDate = _workdate;
		work->company = _company;
	}

	ICloneable* Clone()
	{
        cout << "\ncloneһ�ݼ���...." << endl;
		return new Resume(*this);
	}

	void Display()
	{
		cout << name << " " << sex << " " << age << endl;
		cout << "���������� " << work->workDate << " " << work->company << endl;
	}

private:
    string name;
	string sex;
	int age;
	WorkExperience *work;
};

int main()
{
	Resume *a = new Resume("����");
	a->SetPersonalInfo("��", 29);
	a->SetWorkExperience("1999-2000", "XX��˾");
	a->Display();

	//����clone�Ӹ���
	Resume *b = (Resume*)(a->Clone());
	b->SetWorkExperience("1998-2006", "YY��ҵ");
    b->Display();

	Resume *c = (Resume*)a->Clone();
	c->SetPersonalInfo("Ů", 23);
	c->SetWorkExperience("1998-2003", "ZZ��ҵ");
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
