#ifndef NOTE_H
#define NOTE_H
#include "Expression.h"
//* description: “Ù∑˚¿‡  
class Note:public Expression{
    public:
       void excute(string key,int value){
          string note;
          char szKey[2];
          strncpy(szKey, key.c_str(),key.length());
          switch(szKey[0]){
               case 'C':
                    note="1";
                    break;
               case 'D':
                    note="2";
                    break;
               case 'E':
                    note="3";
                    break;
               case 'F':
                    note="4";
                    break;
               case 'G':
                    note="5";
                    break;
               case 'A':
                    note="6";
                    break;
               case 'B':
                    note="7";
                    break;
          }
          cout<<note<<" ";
       }
};

#endif
