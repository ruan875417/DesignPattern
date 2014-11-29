#include "Note.h"
#include "Scale.h"
#include "Speed.h"
#include "PlayContext.h"

int main(){
    PlayContext context;
    context.setText("T 2 O 2 E 3 G 5 G 5 ");
    
    Expression* expression=NULL;
    while(!context.getText().empty()){
        string str=context.getText().substr(0,1);
        char szKey[2];
        strncpy(szKey, str.c_str(), str.length());
        switch(szKey[0]){
            case 'O':
                 expression=new Scale;
                 break;
            case 'T':
                 expression=new Speed;
                 break;
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'A':
            case 'B':
                 expression=new Note;
                 break;
        }
        if(expression!=NULL){
            expression->interpret(context);
        }  
    }  
    
    system("pause");
    return 0;
}
