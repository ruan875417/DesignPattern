#ifndef PLAYERSTATEMANAGE_H
#define PLAYERSTATEMANAGE_H
#include "PlayerStateBackup.h"
//�������� 
class playerStateManage{
    private:
       PlayerStateBackup* backup;
    public:
       playerStateManage(){}
       void setBackup(PlayerStateBackup* backup){
           this->backup=backup;
       }
       PlayerStateBackup* getBackup(){
           return backup;
       }
};

#endif
