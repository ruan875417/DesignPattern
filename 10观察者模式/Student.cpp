//----------------------------------------------------------------
//    Student.cpp
//----------------------------------------------------------------
#include <iostream>
#include "Student.h"

Student::Student(string name){ 
    this->name=name; 
} 
string Student::getName(){
    return name; 
}
void Student::update(Subject* subject){ 
    cout<<getName()<<",��ʦ�ղ�˵:"<<subject->getContent()<<endl;
}
