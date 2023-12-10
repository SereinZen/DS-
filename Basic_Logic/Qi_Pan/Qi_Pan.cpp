#include "Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include "math.h"





void Qi_Pan::generateWuZiQiBackground() {
    renderTexture->create(width, height);
    renderTexture->clear(sf::Color::White);
    int lineThickness = 1;
    // 创建画笔并设置线条属性
    sf::Color lineColor = sf::Color::Black;
    sf::Color dotColor = sf::Color::Black;

    // 绘制外侧加粗的线条
    int lineWidth = width - 4 * QiRadius;
    sf::RectangleShape outlineRect(sf::Vector2f(lineWidth, lineWidth));
    outlineRect.setOutlineColor(lineColor);
    outlineRect.setOutlineThickness(lineThickness * 3);
    outlineRect.setPosition(QiRadius * 2, QiRadius * 2);
    renderTexture->draw(outlineRect);

    // 绘制网格线
    // 定义横线 宽度为line_width 长度为line_thickness
    sf::RectangleShape line(sf::Vector2f(lineWidth, lineThickness));
    line.setFillColor(lineColor);

    for (int i = 1; i < 14; i++) {
        int pos = gap * i + QiRadius * 2 + (i - 2) * lineThickness;
        line.setPosition(QiRadius * 2, pos);
        renderTexture->draw(line);

    }
    // 定义竖线
    sf::RectangleShape line1(sf::Vector2f(lineThickness, lineWidth));
    line1.setFillColor(lineColor);

    for (int i = 1; i < 14; i++) {
        int pos = gap * i + QiRadius * 2 + (i - 2) * lineThickness;
        line1.setPosition(pos, QiRadius * 2);
        renderTexture->draw(line1);
    }

    // 绘制五个点
    int center = gap * 7 + 9 * lineThickness + QiRadius * 2;
    int offset = 4 * gap + 3 * lineThickness;
    int dotSize = dotRadius * 2;

    sf::CircleShape dot(dotRadius);
    dot.setFillColor(dotColor);

    // 中间
    dot.setPosition(center - dotSize, center - dotSize);
    renderTexture->draw(dot);
    // 左上
    dot.setPosition(center - offset - dotSize, center - offset - dotSize);
    renderTexture->draw(dot);
    // 左下
    dot.setPosition(center + offset - dotSize, center - offset - dotSize);
    renderTexture->draw(dot);
    // 右上
    dot.setPosition(center - offset - dotSize, center + offset - dotSize);
    renderTexture->draw(dot);
    // 右下
    dot.setPosition(center + offset - dotSize, center + offset - dotSize);
    renderTexture->draw(dot);
    renderTexture->display();
//    renderTexture->display();
//    return renderTexture.getTexture();
}



Qi_Pan::Qi_Pan(int width, int height, int dotRadius, int qiRadius, sf::RenderTexture* renderTexture) {
    this->size = 15;
    this->width = height;
    this->height = width;
    this->dotRadius = dotRadius;
    this->color = 1;
    this->QiRadius = qiRadius;
    this->gap = (width - 4 * qiRadius) / 14;
    this->rest = size * size;
    int** qiPan = new int *[15];
    for (int i = 0; i < 15; i++){
        int* temp = new int[15];
        for (int j = 0; j < 15; j++){
            temp[j] = 0;
        }
        qiPan[i] = temp;
    }
    this->qiPan = qiPan;
    // 创建SFML窗口
    this->renderTexture = renderTexture;
    generateWuZiQiBackground();
}
sf::RenderTexture* Qi_Pan::getBackGround() {
    return renderTexture;
}



int Qi_Pan::getSize() {
    return size;
}

int Qi_Pan::getRest() {
    return rest;
}



int Qi_Pan::getColor() {
    return color;
}

int Qi_Pan::getChessSize() {
    return QiRadius;
}

int **Qi_Pan::getQiPan() {
    return qiPan;
}

int Qi_Pan::getGap(){
    return gap;
}

location* Qi_Pan::getLoc() {
    return myloc;
}

location* Qi_Pan::getqiloc() {
    return qiloc;
}

void Qi_Pan::update(location* loc) {
    int x = loc->getX();
    int y = loc->getY();
//    std::cout << x << " " << y << std::endl;
    this->myloc = loc;

    this->qiloc = new location(x * gap + QiRadius * 2 + x, y * gap + QiRadius * 2 + y);
    // 数组与地图的x y相反
    qiPan[y][x] = color;
    if (color == 1){
        color = -1;
    }
    else{
        color = 1;
    }
}


int Qi_Pan::clickValid(location* loc) {
    //判定边界有效性
    //TODO (size - 1) * gap
    int minX = QiRadius;
    int minY = QiRadius;
    int maxX = (size - 1) * gap + QiRadius * 2;
    int maxY = (size - 1) * gap + QiRadius * 2;
    if(loc->getX()<minX || loc->getY()<minY || loc->getX()>maxX || loc->getY()>maxY){
        return 0;
    }

    //判定当前格子有效性
//    int **a=qiPan->getQiPan();
    int indX = round((loc->getX() - minX)/gap);
    int indY = round((loc->getY() - minY)/gap);
    if( qiPan[indX][indY] == 0){
        this->update(new location(indX, indY));

        return 1;
    }
    return 0;
}
//
//fabs(loc->getX() - indX * gap) < QiRadius
//        && fabs(loc->getY() - indY * gap) < QiRadius
//&&


Qi_Pan::~Qi_Pan() {
    for (int i = 0; i < size; ++i) {
        delete[] qiPan[i];
    }
    // 释放存储行指针的内存
    delete[] qiPan;
}


