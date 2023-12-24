/*#ifndef WUZIQI_NEW_AI_H
#define WUZIQI_NEW_AI_H


class AI {
public:
    AI()
    {
        loc=new location(0,0);
    }
    void set(Qi_Pan *qiPan,Qi_Zi *qiZi) {
        this->qiPan = qiPan;
        this->qiZi = qiZi;
    }
    std::pair<int, int> getBestMove() {
        int depth = 4;
        int alpha = INT_MIN;
        int beta = INT_MAX;
        int maxScore = INT_MIN;
        std::pair<int, int> bestMove;

        for (int i = 0; i < qipan->getQiPan().size(); i++) {
            for (int j = 0; j<qipan->getQiPan()[0].size(); j++) {
                if (!qipan->getQiPan()[i][j]) {
                    int score = minimax(i, j, depth, alpha, beta, false);
                    if (score > maxScore) {
                        maxScore = score;
                        bestMove = std::make_pair(i, j);
                    }
                }
            }
        }

        return bestMove;
    }
    void setposition() {
        std::pair<int,int> bestMove = getBestMove();
        loc->set(bestMove.first, bestMove.second);
        qiPan->update(loc);
    }

private:
    Qipan*qipan;

    int evaluate() {
        int score = 0;
        int blackPieces = 0;
        int whitePieces = 0;
        int size=qipan->getBoard().size();
        int **t=qipan->getQiPan();
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

        if (isWin()) {
            score += 1000;
        }

        return score;
    }

    int minimax(int x, int y, int depth, int alpha, int beta, bool isMaximizingPlayer) {
        if (depth == 0 || board.isGameOver(x, y, color)) {
            return evaluate();
        }
        if (isMaximizingPlayer) {
            int maxScore = INT_MIN;
            for (int i = 0; i < qipan->getBoard().size(); i++) {
                for (int j = 0; j < qipan->getBoard()[0].size(); j++) {
                    if (!qipan->getQiPan()[i][j]) {
                        qipan->update(i, j, color);
                        int score = minimax(i, j, depth - 1, alpha, beta, false);
                        qipan->update(i, j, 0);

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
            for (int i = 0; i < qipan->getBoard().size(); i++) {
                for (int j = 0; j < qipan->getBoard()[0].size(); j++) {
                    if (!qipan->getQiPan()[i][j]) {
                        qipan->update(i, j, std::toupper(color));
                        int score = minimax(i, j, depth - 1, alpha, beta, true);
                        qipan->update(i, j, 0);

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
};
#endif //WUZIQI_NEW_AI_H
*/