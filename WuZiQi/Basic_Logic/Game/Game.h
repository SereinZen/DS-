//
// Created by Administrator on 2023/10/19.
//

#ifndef WUZIQI_GAME_H
#define WUZIQI_GAME_H

#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Qi_Shou\Qi_Shou.h"

#define black 1;
#define white 0;

class location{
private:
    int x;
    int y;
public:
    location(int a,int b);
    location* getLoc();
    void set(int a,int b);
    int getX();
    int getY();
};

class location_double{
private:
    double x;
    double y;
public:
    location_double(double a,double b);
    location_double* getLoc();
    void set(double a,double b);
    double getX();
    double getY();
};

class Game {
private:
    Qi_Pan *qiPan;
    Qi_Shou *qiShou;
    Qi_Zi *qiZi;
public:
    Game(Qi_Pan *a,Qi_Shou *b,Qi_Zi *c);
    int victory();
};


#endif //WUZIQI_GAME_H
