#ifndef SCALE_H
#define SCALE_H
#include "Expression.h"
//description: ������  
class Scale:public Expression{
    public:
       void excute(string key,int value){
          string scale;
          switch(value){
               case 1:
                    scale="����";
                    break;
               case 2:
                    scale="����";
                    break;
               case 3:
                    scale="����";
                    break;
          }
          cout<<scale<<" ";
       }
};

#endif
