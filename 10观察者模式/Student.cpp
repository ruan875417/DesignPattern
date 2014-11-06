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
    cout<<getName()<<",老师刚才说:"<<subject->getContent()<<endl;
}
