#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/Music.hpp>
#include "Game.h"
#include "../Qi_Pan/Qi_Pan.h"
#include "../Qi_Shou/Qi_Shou.h"
#include "../Qi_Zi/Qi_Zi.h"
#include "../../ResultPopup/ResultPopup.h"
#include <SFML/Audio.hpp>

//判断游戏胜负函数
int Game::victory() {
    if (qiPan->getLoc() == nullptr){
        return 0;
    }
    int color = -qiPan->getColor();
    int **a=qiPan->getQiPan();
    int size=qiPan->getSize();
    int y=qiPan->getLoc()->getX();
    int x=qiPan->getLoc()->getY();

    //判定平局
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
            std::cout<<"水平方向"<<std::endl;
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
            std::cout<<"竖直方向"<<std::endl;
            return color;
        }

    }

    //右斜方向
    for(int i=0;i<5;i++) {
        if (x - i >= 0 && y - i >= 0
            && x - i + 4 < size && y - i + 4 < size
            && color == a[x - i][y - i]
            && color == a[x - i + 1][y - i + 1]
            && color == a[x - i + 2][y - i + 2]
            && color == a[x - i + 3][y - i + 3]
            && color == a[x - i + 4][y - i + 4]) {
            std::cout<<"右斜方向"<<std::endl;
            return color;
        }
    }

    //左斜方向
    for(int i=0;i<5;i++) {
        if (x+i<size && x+i-4>=0
        && y-i>=0 && y-i+4<size
            && color == a[x + i][y - i]
            && color == a[x + i - 1][y - i + 1]
            && color == a[x + i - 2][y - i + 2]
            && color == a[x + i - 3][y - i + 3]
            && color == a[x + i - 4][y - i + 4]) {
            std::cout<<"左斜方向"<<std::endl;
            return color;
        }
    }
    return 0;
}

//坐标位置类，用于保存数组下标坐标、窗口中的实际坐标
location::location(int a, int b):x(a),y(b){}
void location::set(int a, int b){
    x=a;
    y=b;
}
location *location::getLoc() {return this;}
int location::getX() {return x;}
int location::getY() {return y;}


Game::Game(int width, int height, int dotRadius, int Qi_radius){
    //创建一个游戏，棋盘、棋手、棋子指针，以及创建游戏窗口
    this->renderTexture = new sf::RenderTexture();
    this->qiPan = new Qi_Pan(width, height, dotRadius, Qi_radius, renderTexture);
    this->qiShou = new Qi_Shou();
    this->qiZi = new Qi_Zi(this,renderTexture);
    this->window = new sf::RenderWindow(sf::VideoMode(width, height), "WuZiQi");
    this->sprite = new sf::Sprite();

    //建立各类之间的通信
    qiPan->set(qiZi);
    qiZi->set(qiPan);
    qiShou->set(qiPan,qiZi);
}



//控制游戏流程函数
void Game::play(){
    sf::Music music;
    music.openFromFile("../src/BGM.flac");
    music.setLoop(true); // 设置音乐循环播放
    music.setVolume(50);
    music.play(); // 播放音乐


    while (window->isOpen()){
        //当窗口开启时，游戏持续进行
        while (window->pollEvent(event)){
            //监听游戏右上角是否被点“X”关闭
            if (event.type == sf::Event::Closed){
                window->close();
            }
            else if(event.type == sf::Event::MouseButtonPressed) {
                //没有被关闭则棋手进行操作
                qiShou->play(event,window);
            }
            else if(event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::R) {
                    //TODO 悔棋
                }
            }
        }

        for (auto qi: qiZi->Data_list){
//            renderTexture->clear();
            // 画的顺序不能颠倒！！！
            renderTexture->draw(*qi->c1);

            if (qi->r1 != nullptr and qi->r2 != nullptr){
                renderTexture->draw(*qi->r1);
                renderTexture->draw(*qi->r2);
            }
        }
        //游戏结束后清空窗口，然后关掉（！注意！本部分代码在游戏正常结束时从未运行过！！！）
        window->clear();

        window->draw(sf::Sprite(qiPan->getBackGround()->getTexture()));
//        window->draw(sf::Sprite(renderTexture->getTexture()));

        window->display();
        if (int i = this->victory()){
            ResultPopup rp = ResultPopup(i);
            this->window->close();
        }
    }
}

//游戏结束，析构函数
Game::~Game(){
    delete qiPan;
    delete qiShou;
    delete qiZi;
    delete renderTexture;
    delete window;
    delete sprite;
}