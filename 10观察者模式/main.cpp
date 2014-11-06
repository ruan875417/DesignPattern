//-------------------------------------------------------------
//     demo.cpp
//-------------------------------------------------------------
#include "Student.h"
#include "Teacher.h"
#include<iostream>
using namespace std;

int main(){
    Student* stu1=new Student("zhangshan");
    Student* stu2=new Student("lisi");
    Student* stu3=new Student("wangwu");
    
    Teacher* teacher=new Teacher;
    teacher->attach(stu1);
    teacher->attach(stu2);
    teacher->attach(stu3);
    teacher->notify();
    cout<<endl;
    
    
    teacher->detach(stu1);
    teacher->setContent("����һ����ѧϰC++");
    teacher->notify();
    
    system("pause");
    return 0;
}
