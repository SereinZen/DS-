#ifndef WUZIQI_QI_ZI_H
#define WUZIQI_QI_ZI_H
#include <SFML/Graphics.hpp>




class Qi_Pan;
class Qi_Shou;
class location;

class Qi_Zi {
private:
    location *loc; //
//    int clickValid();// 判断点击是否合法
    int QiRadius;
    sf::RenderTexture* renderTexture;
public:
    Qi_Zi(int QiRadius, sf::RenderTexture* renderTexture);
    ~Qi_Zi();
//    int Luo_Zi();
    sf::RenderTexture * drawQi(int x, int y, int color);
};


#endif //WUZIQI_QI_ZI_H
