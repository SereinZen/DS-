/*#ifndef WUZIQI_NEW_AI_H
#define WUZIQI_NEW_AI_H


class AI {
public:
    AI()
    {
        loc=new location(0,0);
    }
    void set(Qi_Pan *qiPan) {
        this->qiPan = qiPan;
    }
    location* getBestMove() {
        int depth = 4;
        int alpha = INT_MIN;
        int beta = INT_MAX;
        int maxScore = INT_MIN;

        for (int i = 0; i < qipan->getQiPan().size(); i++) {
            for (int j = 0; j<qipan->getQiPan()[0].size(); j++) {
                if (!qipan->getQiPan()[i][j]) {
                    int score = minimax(i, j, depth, alpha, beta, false);
                    if (score > maxScore) {
                        maxScore = score;
                        loc->set(i,j);
                    }
                }
            }
        }

        return loc;
    }
    void setposition() {
        std::pair<int,int> bestMove = getBestMove();
        loc->set(bestMove.first, bestMove.second);
        qiPan->update(loc);
    }
    bool iswin(x,y)
    {
        int **a=qiPan->getQiPan();
        int color=1;
        for(int i=0;i<5;i++) {
            if (y - i >= 0 && y - i + 4 < size
                && color == a[x][y - i]
                && color == a[x][y - i + 1]
                && color == a[x][y - i + 2]
                && color == a[x][y - i + 3]
                && color == a[x][y - i + 4]) {
                return color;
            }
        }
        for(int i=0;i<5;i++) {
            if (x - i >= 0 && x - i + 4 < size
                && color == a[x - i][y]
                && color == a[x - i + 1][y]
                && color == a[x - i + 2][y]
                && color == a[x - i + 3][y]
                && color == a[x - i + 4][y]) {
                return color;
            }

        }
        for(int i=0;i<5;i++) {
            if (x - i >= 0 && y - i >= 0
                