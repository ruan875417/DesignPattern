//---------------------------------------------------------------------
//     Teacher.cpp
//---------------------------------------------------------------------
#include "Teacher.h"

Teacher::Teacher(){ 
     content="���ڿ�ʼ�Ͽ�";
}
void Teacher::attach(Observer* observer){ 
     observerlist.push_back(observer); 
}
void Teacher::detach(Observer* observer){ 
     observerlist.remove(observer); 
}
void Teacher::notify(){
       list <Observer*>::iterator it;
       for(it=observerlist.begin();it!=observerlist.end();++it)
           (*it)->update(this);
}
void Teacher::setContent(string str){ 
     content=str;
}
string Teacher::getContent(){ 
       return content; 
}
