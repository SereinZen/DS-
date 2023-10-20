//
// Created by Administrator on 2023/10/19.
//

#include "Game.h"

#include <iostream>

using namespace std;

location::location(int a, int b):x(a),y(b){}
void location::set(int a, int b){
    x=a;
    y=b;
}
location *location::getLoc() {return this;}
int location::getX() {return x;}
int location::getY() {return y;}


location_double::location_double(double a, double b):x(a),y(b){}
void location_double::set(double a, double b) {
    x=a;
    y=b;
}
location_double *location_double::getLoc() {return this;}
double location_double::getX() {return x;}
double location_double::getY() {return y;}


Game::Game(Qi_Pan *a, Qi_Shou *b, Qi_Zi *c):qiPan(a),qiShou(b),qiZi(c){}

int Game::victory() {
    return black;
}