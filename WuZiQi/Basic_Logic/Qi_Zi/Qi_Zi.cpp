#include "Qi_Zi.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"

Qi_Zi::Qi_Zi(){
    loc=new location(0,0);
}

Qi_Zi::~Qi_Zi(){
    delete loc;
}

int Qi_Zi::clickValid() {
    return 0;
}

int Qi_Zi::Luo_Zi() {
    return 0;
}