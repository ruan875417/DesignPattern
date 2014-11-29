#ifndef SCALE_H
#define SCALE_H
#include "Expression.h"
//description: “ÙΩ◊¿‡  
class Scale:public Expression{
    public:
       void excute(string key,int value){
          string scale;
          switch(value){
               case 1:
                    scale="µÕ“Ù";
                    break;
               case 2:
                    scale="÷–“Ù";
                    break;
               case 3:
                    scale="∏ﬂ“Ù";
                    break;
          }
          cout<<scale<<" ";
       }
};

#endif
