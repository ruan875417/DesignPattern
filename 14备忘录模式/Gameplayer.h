#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H
#include "PlayerStateBackup.h"
#include <iostream>
using namespace std;
//�������� 
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
       // �����ɫ״̬������Ϸ��ɫ��3��״ֵ̬ͨ��ʵ������PlayerStateBackup������
       PlayerStateBackup* savePlayerState(){ return new PlayerStateBackup(vitality,attack,defense); }
       // �ָ���ɫ״̬���ɽ��ⲿ�ġ�PlayerStateBackup���е�״ֵ̬�ָ�����Ϸ��ɫ  
       void recoverState(PlayerStateBackup* stateBackup){
            vitality=stateBackup->getVitality();
            attack=stateBackup->getAttack();
            defense=stateBackup->getDefense();
            cout<<"��һ�ԭ�˴浵�Ľ�ɫ״̬"<<endl;
       }
       void show(){
          cout<<"��ǰ��ɫ״̬������:"<<vitality<<" ������:"<<attack<<" ������:"<<defense<<endl;
       }
};

#endif
