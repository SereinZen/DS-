#include <iostream>
#include "Basic_Logic/Game/Game.h"

void pos_inflection(int x, int y){

}

int main() {
    int width = 1200;
    int height = 1200;
    int dotRadius = 4;
    int qi_radius = 25;
    Game game = Game(width, height, dotRadius, qi_radius);
    game.play();
//    game->display();


    return 0;
}
