#include "Qi_Shou.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Game\Game.h"
#include <iostream>

Qi_Shou::Qi_Shou(){
    loc=new location(0,0);
}

void Qi_Shou::set(Qi_Zi *qiZi){
    this->qiZi=qiZi;
}

Qi_Shou::~Qi_Shou(){
    delete loc;
}

//在走棋部分需要监听事件、游戏窗口的传入并进行控制
void Qi_Shou::play(sf::Event event,sf::RenderWindow *window) {
    //监听鼠标左键是否被点击
    if (event.type == sf::Event::MouseButtonPressed){
        if (event.mouseButton.button == sf::Mouse::Left){
            // 获取鼠标点击的坐标
            sf::Vector2i mousePosition = sf::Mouse::getPosition(*window);
            std::cout << "鼠标坐标：" << mousePosition.x << "," << mousePosition.y << std::endl;

            //将当前鼠标位置传入落子函数中
            loc->set(mousePosition.x, mousePosition.y);

            qiZi->Luo_Zi(loc);
        }
    }
}