#ifndef WUZIQI_AI_H
#define WUZIQI_AI_H

#include "../Basic_Logic/Qi_Pan/Qi_Pan.h"
#include "../Basic_Logic/Game/Game.h"
#include <cmath>
class location;
using namespace std;

class AI{
    Qi_Pan *qiPan;
    location *pos;
    int **a;
    location* evaluate();
    int evaluateScore(int color);
    void getScore(int color,string line);
    int curLianWu = 0;
    int curChongSi = 0;
    int oppChongSi = 0;
    int curHuoSi = 0;
    int oppHuoSi = 0;
    int curHuoSan = 0;
    int oppHuoSan = 0;
    int curMianSan = 0;
    int oppMianSan = 0;
    int curHuoEr = 0;
    int oppHuoEr = 0;
    int curMianEr = 0;
    int oppMianEr = 0;
    int curSingle = 0;
    int oppSingle = 0;
public:
    AI();
    void set(Qi_Pan *qiPan);
    location* getBestMove();
    ~AI();

};

#endif //WUZIQI_AI_H