#ifndef SPEED_H
#define SPEED_H
#include "Expression.h"
//description: �����ٶ���  
class Speed:public Expression{
    public:
       void excute(string key,int value){
          string speed;
          char szKey[2];
          strncpy(szKey, key.c_str(),key.length());
          if(value<500){
             speed="����";
          }else if(value>=1000){
             speed="����";
          }else{
             speed="����";
          }
          cout<<speed<<" ";
       }
};

#endif
