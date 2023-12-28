#include "Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include "iostream"
#include <SFML/Graphics.hpp>
#include <cmath>

void Qi_Pan::generateWuZiQiBackground() {
    renderTexture->create(width, height);
    renderTexture->clear();

    sf::Texture image;
    if (!image.loadFromFile("../src/background.png")) {
        std::cout << "背景图片加载失败" << std::endl;
        return;
    }

    sf::Sprite sprite(image);
    renderTexture->draw(sprite);

    int lineThickness = 1;
    // 创建画笔并设置线条属性
    sf::Color lineColor = sf::Color::Black;
    sf::Color dotColor = sf::Color::Black;

    // 绘制外侧加粗的线条
    int lineWidth = width - 4 * chessRadius;
    sf::RectangleShape outlineRect(sf::Vector2f(lineWidth, lineWidth));
    outlineRect.setOutlineColor(lineColor);
    outlineRect.setOutlineThickness(lineThickness * 3);
    outlineRect.setPosition(chessRadius * 2, chessRadius * 2);
    // 默认填充无色
    outlineRect.setFillColor(sf::Color::Transparent);
    renderTexture->draw(outlineRect);

    // 绘制网格线
    // 定义横线 宽度为line_width 长度为line_thickness
    sf::RectangleShape line(sf::Vector2f(lineWidth, lineThickness));
    line.setFillColor(lineColor);

    for (int i = 1; i < 14; i++) {
        int pos = gap * i + chessRadius * 2 + (i - 2) * lineThickness;
        line.setPosition(chessRadius * 2, pos);
        renderTexture->draw(line);

    }
    // 定义竖线
    sf::RectangleShape line1(sf::Vector2f(lineThickness, lineWidth));
    line1.setFillColor(lineColor);

    for (int i = 1; i < 14; i++) {
        int pos = gap * i + chessRadius * 2 + (i - 2) * lineThickness;
        line1.setPosition(pos, chessRadius * 2);
        renderTexture->draw(line1);
    }

    // 绘制五个点
    int center = gap * 7 + 9 * lineThickness + chessRadius * 2;
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
}

//构造函数，由Game类控制传入，实时建立窗口与初始化棋盘以及各个变量
Qi_Pan::Qi_Pan(int width, int height, int dotRadius, int qiRadius) {
    this->myLoc = nullptr;
    this->chessLoc = new location(0, 0);
    this->size = 15;
    this->width = height;
    this->height = width;
    this->dotRadius = dotRadius;
    this->color = 1;
    this->chessRadius = qiRadius;
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
    this->renderTexture = new sf::RenderTexture();
    generateWuZiQiBackground();
}

void Qi_Pan::qi_regret() {
    if (!qiZi->Data_list.empty()){
        int i=0;
        if(game->getMode()==0){
            i=1;
        }
        if(game->getMode()==1){
            i=2;
        }
        for(int k=0;k<i;k++){
            QiZi_Data* cur_qi = *(qiZi->Data_list.end() - 1);
            qiZi->Data_list.pop_back();
            this->color = -this->color;
            this->getQiPan()[cur_qi->map_loc->getY()][cur_qi->map_loc->getX()] = 0;
            if(color==1){
                std::cout<<"黑棋悔棋，";
            }
            else
                std::cout<<"白棋悔棋，";
            std::cout<<"悔棋坐标："<<cur_qi->map_loc->getY()<<","<<cur_qi->map_loc->getX()<<std::endl;
        }
    }
    else{
        std::cout << "没有棋子，无法悔棋" << std::endl;
    }
}

sf::RenderTexture* Qi_Pan::getBackGround() {
    return renderTexture;
}

//返回棋盘大小（15*15）
int Qi_Pan::getSize() {
    return size;
}
//返回棋盘中剩余空位
int Qi_Pan::getRest() {
    return rest;
}
//返回当前棋子颜色
int Qi_Pan::getColor() {
    return color;
}
//返回棋子大小
int Qi_Pan::getChessSize() {
    return chessRadius;
}
//返回棋盘数组
int **Qi_Pan::getQiPan() {
    return qiPan;
}
//返回棋盘中线条的间隔
int Qi_Pan::getGap(){
    return gap;
}
//返回当前棋子在数组中的位置
location* Qi_Pan::getLoc() {
    //当前棋子的数组坐标
    return myLoc;
}
//返回当前棋子的实际位置
location* Qi_Pan::getChessLoc() {
    //当前棋子的实际坐标
    return chessLoc;
}
//在落子后更新棋盘
void Qi_Pan::update(location* loc) {
    this->myLoc = loc;
    rest--;

    this->chessLoc->set(myLoc->getX() * (gap + 1) + chessRadius * 2, myLoc->getY() * (gap + 1) + chessRadius * 2);
    // 数组与地图的实际位置x y相反
    qiPan[myLoc->getY()][myLoc->getX()] = color;
    //进行更换棋子颜色（换手）
    if (color == 1){
        color = -1;
    }
    else{
        color = 1;
    }
}

void Qi_Pan::set(Game *game,Qi_Zi* qiZi){
    this->game = game;
    this->qiZi = qiZi;
}



Qi_Pan::~Qi_Pan() {
    for (int i = 0; i < size; ++i) {
        delete[] qiPan[i];
    }
    // 释放存储行指针的内存
    delete[] qiPan;
    delete myLoc;
    delete chessLoc;
}


