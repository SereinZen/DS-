#include "Qi_Zi.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Shou\Qi_Shou.h"
#include "..\Game\Game.h"
#include <SFML/Graphics.hpp>
#include <cmath>


sf::RenderTexture * Qi_Zi::drawQi(int x, int y, int color) {

    sf::CircleShape qi_zi(QiRadius);
    qi_zi.setOutlineColor(sf::Color::Black);
    qi_zi.setOutlineThickness(1);
    if (color == 1){
        qi_zi.setFillColor(sf::Color::Black);  // 设置棋子颜色
    }
    else{
        qi_zi.setFillColor(sf::Color::White);  // 设置棋子颜色
    }
    // 设置棋子位置
    qi_zi.setPosition(x - QiRadius, y - QiRadius);
    renderTexture->draw(qi_zi);
    renderTexture->display();
    return renderTexture;
}



Qi_Zi::Qi_Zi(int qiRadius, sf::RenderTexture* renderTexture){
    loc=new location(0,0);
    this->QiRadius = qiRadius;
//    this->color = 1;
    this->renderTexture = renderTexture;
}

Qi_Zi::~Qi_Zi(){
    delete loc;
}


//int Qi_Zi::Luo_Zi() {
//    return 0;
//}


//Qi_Zi::Qi_Zi(){
//    loc=new location(0,0);
//    border=new location(0,0);
//    this->border=border;
//}
//
//Qi_Zi::~Qi_Zi(){
//    delete loc;
//    delete border;
//}



//int Qi_Zi::Luo_Zi(location *l) {
//    this->loc=l;
//    if(clickValid()){
//        int **a=qiPan->getQiPan();
//        a[loc->getX()][loc->getY()]=qiPan->getColor();
//        if(qiPan->getColor()==1){
//            qiPan->update(-1,a,loc);
//        } else{
//            qiPan->update(1,a,loc);
//        }
//        return 1;
//    }
//    return 0;
//}



