#include "GamePlayer.h"
#include "PlayerStateBackup.h"
#include "playerStateManage.h"
using namespace std;

int main(){
    GamePlayer* gameplayer=new GamePlayer;
    gameplayer->setInistance(100,100,100,"��ǰ��ɫ��ʼ״̬");
    gameplayer->show();
    
    playerStateManage* manage=new playerStateManage;
    manage->setBackup(gameplayer->savePlayerState());
    
    gameplayer->setInistance(1,1,1,"��ǰ��ɫ������");
    gameplayer->show();
    
    gameplayer->recoverState(manage->getBackup());
    gameplayer->show();
    
    delete gameplayer;
    delete manage; 
    
    system("pause");
    return 0;
}
