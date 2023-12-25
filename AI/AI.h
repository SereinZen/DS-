#ifndef WUZIQI_AI_H
#define WUZIQI_AI_H

#include "../Basic_Logic/Qi_Pan/Qi_Pan.h"
#include "../Basic_Logic/Game/Game.h"

class location;

class AI{
    Game *game;
    Qi_Pan *qiPan;
    location *loc;
    int i=0;
public:
    AI();
    void set(Game *game,Qi_Pan *qiPan);
    location* getBestMove();
};

#endif //WUZIQI_AI_H