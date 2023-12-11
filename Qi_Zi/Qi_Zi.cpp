#include "Qi_Zi.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

//显示棋子函数
sf::RenderTexture * Qi_Zi::drawChess() {

    sf::CircleShape qi_zi(qiPan->getChessSize());
    qi_zi.setOutlineColor(sf::Color::Black);
    qi_zi.setOutlineThickness(1);
    //调用显示棋子函数的时候此时已经更新棋盘（已经换手了），所以需要反向判定当前颜色
    if (qiPan->getColor() == -1) {
        qi_zi.setFillColor(sf::Color::Black);  // 设置棋子颜色
    } else {
        qi_zi.setFillColor(sf::Color::White);  // 设置棋子颜色
    }
    // 设置棋子位置
    qi_zi.setPosition(qiPan->getChessLoc()->getX() - qiPan->getChessSize(),
                      qiPan->getChessLoc()->getY() - qiPan->getChessSize());
    renderTexture->draw(qi_zi);
    renderTexture->display();
    return renderTexture;
}


//构造函数
Qi_Zi::Qi_Zi(Game *game,sf::RenderTexture* renderTexture){
    loc=new location(0,0);
    this->game=game;
    this->renderTexture = renderTexture;
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
        drawChess();
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