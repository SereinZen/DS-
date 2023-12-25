#ifndef WUZIQI_AI_H
#define WUZIQI_AI_H
#include "Qi_Pan/Qi_Pan.h"


class AI{
public:
    location* loc;
    AI();
    ~AI();
    void set(Qi_Pan* qiPan);
    Qi_Pan* qiPan;
    int evaluate(int x, int y);
    location *getBestMove();

    bool isWin(int x, int y);

    int minimax(int x, int y, int depth, int alpha, int beta, bool isMaximizingPlayer);
};






#endif //WUZIQI_AI_H
