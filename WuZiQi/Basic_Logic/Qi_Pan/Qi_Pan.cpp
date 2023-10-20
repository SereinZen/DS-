#include "Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include <cstdlib>

using namespace std;

Qi_Pan::Qi_Pan() {

}

int Qi_Pan::getSize() {
    return size;
}

location* Qi_Pan::getLoc() {
    return loc;
}

int Qi_Pan::getColor() {
    return color;
}

int Qi_Pan::getChessSize() {
    return chessSize;
}

int **Qi_Pan::getQiPan() {
    return qiPan;
}


void Qi_Pan::getChessPicture(location *loc) {

}

void Qi_Pan::update(int color, int **qiPan, location *loc) {
    this->color = color;
    this->qiPan = qiPan;
    this->loc = loc;
}

void Qi_Pan::display() {

    system("python Qi_Pan.py");


}

Qi_Pan::~Qi_Pan() {
    delete loc;
    for (int i = 0; i < size; ++i) {
        delete[] qiPan[i];
    }
    // 释放存储行指针的内存
    delete[] qiPan;
}


