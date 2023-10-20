#include "Game.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Qi_Zi\Qi_Zi.h"

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

Game::Game(Qi_Pan *a, Qi_Shou *b, Qi_Zi *c){
    a=new Qi_Pan;
    qiPan=a;
    b=new Qi_Shou;
    qiShou=b;
    c=new Qi_Zi;
    qiZi=c;
}

Game::~Game(){
    delete qiPan;
    delete qiShou;
    delete qiZi;
}

int Game::victory() {
    return black;
}

void Game::play(){

}