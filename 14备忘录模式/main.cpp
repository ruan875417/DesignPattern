#include "GamePlayer.h"
#include "PlayerStateBackup.h"
#include "playerStateManage.h"
using namespace std;

int main(){
    GamePlayer* gameplayer=new GamePlayer;
    gameplayer->setInistance(100,100,100,"当前角色初始状态");
    gameplayer->show();
    
    playerStateManage* manage=new playerStateManage;
    manage->setBackup(gameplayer->savePlayerState());
    
    gameplayer->setInistance(1,1,1,"当前角色被扁了");
    gameplayer->show();
    
    gameplayer->recoverState(manage->getBackup());
    gameplayer->show();
    
    delete gameplayer;
    delete manage; 
    
    system("pause");
    return 0;
}
