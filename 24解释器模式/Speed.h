#ifndef SPEED_H
#define SPEED_H
#include "Expression.h"
//description: 演奏速度类  
class Speed:public Expression{
    public:
       void excute(string key,int value){
          string speed;
          char szKey[2];
          strncpy(szKey, key.c_str(),key.length());
          if(value<500){
             speed="快速";
          }else if(value>=1000){
             speed="慢速";
          }else{
             speed="中速";
          }
          cout<<speed<<" ";
       }
};

#endif
