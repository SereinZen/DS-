#ifndef WUZIQI_QI_SHOU_H
#define WUZIQI_QI_SHOU_H

#include <SFML/Graphics.hpp>
class location;
class Qi_Pan;
class Qi_Zi;

class Qi_Shou {
private:
    location *loc;//鼠标点击后的x、y坐标
    Qi_Zi *qiZi;//棋子指针
    //还需完成鼠标控制部分的内容
public:
    Qi_Shou();//构造函数
    ~Qi_Shou();//析构函数
    void set(Qi_Zi *qiZi);//初始化通信函数
    void play(sf::Event event,sf::RenderWindow *window);//棋手走棋函数
};


#endif //WUZIQI_QI_SHOU_H
