#ifndef PLAYCONTEXT_H
#define PLAYCONTEXT_H
#include<iostream>
using namespace std;

class PlayContext{
   private:
       string text;
   public:
       string getText(){ return text; }
       void setText(string text){
          this->text=text;
       }
};

#endif
