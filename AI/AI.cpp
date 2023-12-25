#include "AI.h"
#include "../Basic_Logic/Qi_Pan/Qi_Pan.h"
#include "../Basic_Logic/Game/Game.h"

AI::AI()
{
    loc=new location(0,0);
}
void AI::set(Qi_Pan* qiPan) {
    this->qiPan = qiPan;
}
location* AI::getBestMove() {
    int depth = 4;
    int alpha = INT_MIN;
    int beta = INT_MAX;
    int maxScore = INT_MIN;

    for (int i = 0; i < qiPan->getSize(); i++) {
        for (int j = 0; j<qiPan->getSize(); j++) {
            if (!qiPan->getQiPan()[i][j]) {
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
bool AI::isWin(int x,int y)
{
    int size=qiPan->getSize();
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
            && x - i + 4 < size && y - i + 4 < size
            && color == a[x - i][y - i]
            && color == a[x - i + 1][y - i + 1]
            && color == a[x - i + 2][y - i + 2]
            && color == a[x - i + 3][y - i + 3]
            && color == a[x - i + 4][y - i + 4]) {
            return color;
        }
    }
    for(int i=0;i<5;i++) {
        if (x - i - 4>= 0 && y - i >= 0
            && x - i + 0 < size && y + i + 4 < size
            && color == a[x - i][y - i]
            && color == a[x - i - 4][y + i + 1]
            && color == a[x - i - 3][y + i + 2]
            && color == a[x - i - 2][y + i + 3]
            && color == a[x - i - 1][y + i + 4]) {
            return color;
        }
    }
    return false;
}

int AI::evaluate(int x,int y) {
    int score = 0;
    int blackPieces = 0;
    int whitePieces = 0;
    int size=qiPan->getSize();
    int **t=qiPan->getQiPan();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (t[i][j]==1) {
                blackPieces++;
            }
            else if(t[i][j]==-1) {
                whitePieces++;
            }
        }
    }
    score = blackPieces - whitePieces;
    score += blackPieces / size * 5;

    if (isWin(x,y)) {
        score += 1000;
    }

    return score;
}


int AI::minimax(int x, int y, int depth, int alpha, int beta, bool isMaximizingPlayer) {
    if (depth == 0 || isWin(x,y)) {
        return evaluate(x,y);
    }
    if (isMaximizingPlayer) {
        int maxScore = INT_MIN;
        for (int i = 0; i < qiPan->getSize(); i++) {
            for (int j = 0; j < qiPan->getSize(); j++) {
                if (!qiPan->getQiPan()[i][j]) {
//                    FIXME 修改update
//                    qiPan->update(i, j);
                    int score = minimax(i, j, depth - 1, alpha, beta, false);
//                    qiPan->update(i, j);
//
                    maxScore = std::max(maxScore, score);
                    alpha = std::max(alpha, maxScore);

                    if (beta <= alpha) {
                        break;  // 进行alpha-beta剪枝
                    }
                }
            }
        }
        return maxScore;
    } else {
        int minScore = INT_MAX;
        for (int i = 0; i < qiPan->getSize(); i++) {
            for (int j = 0; j < qiPan->getSize(); j++) {
                if (!qiPan->getQiPan()[i][j]) {
//                    FIXME 修改update
//                    qiPan->update(i, j, std::toupper(qiPan->getColor()));
                    int score = minimax(i, j, depth - 1, alpha, beta, true);
//                    qiPan->update(i, j, 0);

                    minScore = std::min(minScore, score);
                    beta = std::min(beta, minScore);

                    if (beta <= alpha) {
                        break;  // 进行alpha-beta剪枝
                    }
                }
            }
        }

        return minScore;
    }
}