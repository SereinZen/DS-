#include "Basic_Logic/Game/Game.h"

int main() {
    //设置棋盘尺寸
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;
    //创建游戏
    Game game = Game(width, height, dotRadius, qi_radius);
    //游戏开始
    game.play();

    return 0;
}
