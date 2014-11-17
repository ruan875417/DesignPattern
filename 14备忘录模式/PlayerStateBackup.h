#ifndef PLAYERSTATEBACKUP_H
#define PLAYERSTATEBACKUP_H
//±¸ÍüÂ¼Àà 
class PlayerStateBackup{
   private:
       int vitality;
       int attack;
       int defense;
   public:
       PlayerStateBackup(int vitality,int attack,int defense){
          this->vitality=vitality;
          this->attack=attack;
          this->defense=defense;
       }
       int getVitality(){ return  vitality; }
       int getAttack(){ return attack; }
       int getDefense(){ return  defense; }
};

#endif
