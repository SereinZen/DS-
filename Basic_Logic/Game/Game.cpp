#include "Game.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include <SFML/Graphics.hpp>
#include "iostream"


int Game::victory() {

    int color = -qiPan->getColor();
    int **a=qiPan->getQiPan();
    int size=qiPan->getSize();
    int x=qiPan->getLoc()->getX();
    int y=qiPan->getLoc()->getY();

    //判定平局 (棋盘全部格子都下满了)
    for(int i=0;i<size;i++) {
        for (int j = 0; j < size; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }

    //如果保存了int rest，就用下面这段：
    if(qiPan->getRest()==0){
        //TODO 判断平局
        return 2;
    }

    //水平方向
    for(int i=0;i<5;i++) {
        if (y - i >= 0 && y - i + 4 < size
            && color == a[x][y - i]
            && color == a[x][y - i + 1]
            && color == a[x][y - i + 2]
            && color == a[x][y - i + 3]
            && color == a[x][y - i + 4]) {
            return color;
        }
    }

    //竖直方向
    for(int i=0;i<5;i++) {
        if (x - i >= 0 && x - i + 4 < size
            && color == a[x - i][y]
            && color == a[x - i + 1][y]
            && color == a[x - i + 2][y]
            && color == a[x - i + 3][y]
            && color == a[x - i + 4][y]) {
            return color;
        }

    }

    //斜方向
    for(int i=0;i<5;i++) {
        if (x - i >= 0 && y - i >= 0
            && x - i + 4 < size && y - i + 4 < size
            && color == a[x - i][y - i]
            && color == a[x - i + 1][y - i + 1]
            && color == a[x - i + 2][y - i + 2]
            && color == a[x - i + 3][y - i + 3]
            && color == a[x - i + 4][y - i + 4]) {
            return color;
        }
    }
    return 0;
}

location::location(int a, int b):x(a),y(b){}
void location::set(int a, int b){
    x=a;
    y=b;
}
location *location::getLoc() {return this;}
int location::getX() {return x;}
int location::getY() {return y;}


//location_double::location_double(double a, double b):x(a),y(b){}
//void location_double::set(int a, int b) {
//    x=a;
//    y=b;
//}
location_double *location_double::getLoc() {return this;}
int location_double::getX() {return x;}
int location_double::getY() {return y;}

Game::Game(int width, int height, int dotRadius, int Qi_radius){
    this->renderTexture = new sf::RenderTexture();
    this->qiPan = new Qi_Pan(width, height, dotRadius, Qi_radius, renderTexture);
//    this->qiShou = new Qi_Shou();
    this->qiZi = new Qi_Zi(Qi_radius, renderTexture);
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), "WuZiQi");
    this->sprite = new sf::Sprite();
}




void Game::play(){
    while (window->isOpen()){
        sf::Event event;
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window->close();
            }
            else if (event.type == sf::Event::MouseButtonPressed){
                if (event.mouseButton.button == sf::Mouse::Left){
                    // 获取鼠标点击的坐标
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
                    std::cout << "鼠标坐标（坐标系）" << mousePosition.x << ", " << mousePosition.y << std::endl;
                    location* loc = new location(mousePosition.x, mousePosition.y);
                    if (qiPan->clickValid(loc) == 1){
                        qiZi->drawQi(qiPan->getqiloc()->getX(), qiPan->getqiloc()->getY(), qiPan->getColor());
                        if (victory() != 0){
                            std::cout << "游戏结束" << std::endl;
                        }
                    }
                    else{
                        std::cout << "点击不合法" << std::endl;
                    }
                }
            }
        }
        window->clear();
        window->draw(sf::Sprite(renderTexture->getTexture()));
        window->display();
    }
}


Game::~Game(){
    delete qiPan;
//    delete qiShou;
    delete qiZi;
}