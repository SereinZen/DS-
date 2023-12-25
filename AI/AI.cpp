#include "AI.h"

AI::AI() {
    this->game= nullptr;
    this->qiPan= nullptr;
    this->loc= new location(0,0);
}

void AI::set(Game *game, Qi_Pan *qiPan) {
    this->game=game;
    this->qiPan=qiPan;
}

location* AI::getBestMove() {
    int minX = qiPan->getChessSize();
    int minY = qiPan->getChessSize();
    int indX = 0;
    int indY = 0;
    loc->set(minX+i*(qiPan->getGap()+1),minY+i*(qiPan->getGap()+1));
    i++;
    return loc;
}