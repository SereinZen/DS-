#include "Qi_Zi.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include "../../ResultPopup/ResultPopup.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <SFML/Audio.hpp>
//显示棋子函数
sf::RenderTexture* Qi_Zi::drawChess(location* loc) {
    location* cur_loc;
    if (loc != nullptr){
        cur_loc = loc;

    }
    else{
        cur_loc = qiPan->getChessLoc();
    }

    sf::CircleShape* qi_zi = new sf::CircleShape(qiPan->getChessSize());
    qi_zi->setOutlineColor(sf::Color::Black);
    qi_zi->setOutlineThickness(1);
//    shi_zi->getDefaultView();
    //调用显示棋子函数的时候此时已经更新棋盘（已经换手了），所以需要反向判定当前颜色
    if (qiPan->getColor() == -1) {
        qi_zi->setFillColor(sf::Color::Black);  // 设置棋子颜色
    } else {
        qi_zi->setFillColor(sf::Color::White);  // 设置棋子颜色
    }
    // 设置棋子位置
    qi_zi->setPosition(cur_loc->getX() - qiPan->getChessSize(),
                      cur_loc->getY() - qiPan->getChessSize());
    QiZi_Data* qiZiData = new QiZi_Data(qiPan->getColor(), nullptr, nullptr, qi_zi);
//    renderTexture->draw(*qi_zi);

    if (loc == nullptr){
        int Radius = qiPan->getChessSize();
        // 横线
        sf::RectangleShape* horizontalLine = new sf::RectangleShape(sf::Vector2f(Radius * 0.45, 1));
        horizontalLine->setFillColor(sf::Color::Red);
        horizontalLine->setPosition(cur_loc->getX() - Radius * 0.2, cur_loc->getY());
//        renderTexture->draw(*horizontalLine);

        // 绘制竖线
        sf::RectangleShape* verticalLine = new sf::RectangleShape(sf::Vector2f(1, Radius * 0.45));
        verticalLine->setFillColor(sf::Color::Red);
        verticalLine->setPosition(cur_loc->getX(), cur_loc->getY() - Radius * 0.2);
//        renderTexture->draw(*verticalLine);
        // 存储棋子 to regret
        qiZiData->r1 = horizontalLine;
        qiZiData->r2 = verticalLine;
    }
    Data_list.push_back(qiZiData);
//    renderTexture->display();

    return renderTexture;

}


void Qi_Zi::regret_qi() {
    if (!Data_list.empty()){
//        QiZi_Data* cur_qiZi = this->Data_list.back();
//        this->Data_list.pop_back();
//        QiZi_Data* next_qiZi = this->Data_list.back();
//        this->Data_list.pop_back();

//        cur_qiZi->r1->setFillColor(sf::Color::Transparent);
//        cur_qiZi->r2->setFillColor(sf::Color::Transparent);
//        cur_qiZi->c1->setFillColor(sf::Color::Red);
//        cur_qiZi->c1->setOutlineColor(sf::Color::Red);

//        next_qiZi->c1->setFillColor(sf::Color::Red);
//        next_qiZi->c1->setOutlineColor(sf::Color::Red);
//        cur_qiZi->r1->setOutlineColor(sf::Color::Transparent);
//        cur_qiZi->r2->setOutlineColor(sf::Color::Transparent);

//        this->renderTexture->draw(*cur_qiZi->r1);
//        this->renderTexture->draw(*cur_qiZi->c1);
//        this->renderTexture->draw(*cur_qiZi->r2);
//        game->window->clear();
//        game->window->draw(sf::Sprite(renderTexture->getTexture()));
//        game->window->display();
//        delete cur_qiZi;
    }
}

//构造函数
Qi_Zi::Qi_Zi(Game *game,sf::RenderTexture* renderTexture){
    loc=new location(0,0);
    this->game=game;
    this->renderTexture = renderTexture;
//    this->shi_zi = this->generate_ShiZi();

}

//析构函数
Qi_Zi::~Qi_Zi(){
    delete loc;
}

//判断鼠标点击有效性
int Qi_Zi::clickValid() {
        //判定边界有效性
        //TODO (size - 1) * gap
        int minX = qiPan->getChessSize();
        int minY = qiPan->getChessSize();
        int maxX = (qiPan->getChessSize() - 1) * (qiPan->getGap()+1) + qiPan->getChessSize() * 3;
        int maxY = (qiPan->getChessSize() - 1) * (qiPan->getGap()+1) + qiPan->getChessSize() * 3;
        if(loc->getX()<minX || loc->getY()<minY || loc->getX()>maxX || loc->getY()>maxY){
            return 0;
        }

        //判定当前格子有效性
        //四舍五入映射当前鼠标位置对应的棋盘数组下标
        int indX = round((loc->getX() - minX)/(qiPan->getGap()+1));
        int indY = round((loc->getY() - minY)/(qiPan->getGap()+1));

        std::cout<<"下标位置："<<indY<<","<<indX<<std::endl;

        //每个点位控制的有效范围为棋子本身的大小，超出范围依然为无效点击
        if(fabs((loc->getX() - minX) - indX * (qiPan->getGap()+1)) < 2*qiPan->getChessSize()
           && fabs((loc->getY() - minY) - indY * (qiPan->getGap()+1)) < 2*qiPan->getChessSize()
           && qiPan->getQiPan()[indY][indX] == 0) {
            //将下标位置传入棋盘类并更新棋盘
            qiPan->update(new location(indX, indY));
//            for (int i = 0; i < qiPan->getSize(); i++){
//                std::cout << i + 1 << " ";
//                for (int j = 0; j < qiPan->getSize(); j++){
//                    std::cout << qiPan->getQiPan()[i][j] << " ";
//                }
//                std::cout << std::endl;
//            }
            //返回1为有效点击
            return 1;
        }
        //返回0为无效点击
        return 0;
}
//初始化通信函数
void Qi_Zi::set(Qi_Pan *qiPan){
    this->qiPan=qiPan;
}
//落子函数
void Qi_Zi::Luo_Zi(location *l) {
    //保存当前鼠标位置
    loc->set(l->getX(),l->getY());
    if (clickValid()){
        //如果点击有效，就将棋子显示出来
        drawChess(nullptr);

        //音效
        sf::SoundBuffer buffer;
        buffer.loadFromFile("../src/Luo_Zi_Yin_Xiao.flac");
        sf::Sound sound;
        sound.setBuffer(buffer);

        // 播放音效
        sound.play();

        // 等待音效播放完成
        while (sound.getStatus() == sf::Sound::Playing) {
            // 可以添加一些其他操作，或者直接休眠一段时间
            sf::sleep(sf::milliseconds(100));
        }

        //判断游戏是否结束
        if(int i=game->victory()){

            if(i==1){
                std::cout<<"黑棋获胜"<<std::endl;
            }
            if(i==-1){
                std::cout<<"白棋获胜"<<std::endl;
            }
            if(i==2){
                std::cout<<"平局"<<std::endl;
            }
            std::cout<<"游戏结束"<<std::endl;
        }
    }
    else{
        std::cout<<"点击不合法"<<std::endl;
    }
}