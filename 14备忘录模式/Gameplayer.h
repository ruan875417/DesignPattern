#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include "PlayerStateBackup.h"
#include <iostream>
using namespace std;
//发起人类 
class PlayerStateBackup;
class GamePlayer{
   private:
       int vitality;
       int attack;
       int defense;
   public:
       GamePlayer(){} 
       void setInistance(int vitality,int attack,int defense,string str){
          this->vitality=vitality;
          this->attack=attack;
          this->defense=defense;
          cout<<str<<endl;
       }
       // 保存角色状态。将游戏角色的3种状态值通过实例化“PlayerStateBackup”返回
       PlayerStateBackup* savePlayerState(){ return new PlayerStateBackup(vitality,attack,defense); }
       // 恢复角色状态。可将外部的“PlayerStateBackup”中的状态值恢复给游戏角色  
       void recoverState(PlayerStateBackup* stateBackup){
            vitality=stateBackup->getVitality();
            attack=stateBackup->getAttack();
            defense=stateBackup->getDefense();
            cout<<"玩家还原了存档的角色状态"<<endl;
       }
       void show(){
          cout<<"当前角色状态：体力:"<<vitality<<" 攻击力:"<<attack<<" 防御力:"<<defense<<endl;
       }
};

#endif
