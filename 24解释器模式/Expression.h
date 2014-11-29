#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "PlayContext.h"
// description: ���ʽ��  
class Expression{
    public:
        void interpret(PlayContext& context){
            if(context.getText().empty()){
                return; 
            }else{
                string playKey=context.getText().substr(0,1);//���playKey 
                context.setText(context.getText().substr(2));
                
                size_t found=context.getText().find(" ");
                string strPlayValue=context.getText().substr(0,found);
                int playValue=atoi(strPlayValue.c_str());//���playValue
       
                context.setText(context.getText().substr(found+1));//���playKey��playValue����������ı�ɾ�� 
                excute(playKey,playValue);
            }
        }
        virtual void excute(string key,int value)=0;
};

#endif
