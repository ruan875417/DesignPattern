#ifndef PLAYERSTATEMANAGE_H
#define PLAYERSTATEMANAGE_H
#include "PlayerStateBackup.h"
//管理者类 
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
