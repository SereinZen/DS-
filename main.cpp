#include "Basic_Logic/Game/Game.h"

int main() {
    //�������̳ߴ�
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;
    //������Ϸ
    Game game = Game(width, height, dotRadius, qi_radius);
    //��Ϸ��ʼ
    game.play();

    return 0;
}
