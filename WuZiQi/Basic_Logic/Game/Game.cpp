//
// Created by Administrator on 2023/10/19.
//

#include "Game.h"

#include <iostream>

using namespace std;

Game::Game(Qi_Pan *a, Qi_Shou *b, Qi_Zi *c):qiPan(a),qiShou(b),qiZi(c){}

int Game::victory() {
    return black;
}