#ifndef WUZIQI_QI_ZI_H
#define WUZIQI_QI_ZI_H
#include <SFML/Graphics.hpp>
#include "vector"

class Qi_Pan;
class Qi_Shou;
class location;
class Game;
class QiZi_Data{
public:
    int color;
    location* map_loc;
    location* real_loc;

    QiZi_Data(int color, location* map_list){
        this->color = color;
        this->map_loc = map_list;
    }
};

class Qi_Zi {
private:
    location *loc; //当前棋子实际坐标（落子后将映射为数组坐标）
    Qi_Pan *qiPan;//棋盘指针
    Game *game;//游戏指针，用于调用victory判定胜负函数
    sf::RenderTexture* renderTexture;//画板显示棋子
    std::vector<QiZi_Data*>* Data_list;
    int clickValid();//判断鼠标点击的位置是否有效
public:
    Qi_Zi(Game *game,sf::RenderTexture* renderTexture);//构造函数，需要获取当前游戏指针和游戏窗口画板
    ~Qi_Zi();//析构函数
    void set(Qi_Pan *qiPan);//初始化通信函数
    void Luo_Zi(location *l);//落子函数，需要传入鼠标点击的坐标
    sf::RenderTexture * drawChess(location* loc);//落子后显示棋子
    void regret_qi();
};


#endif //WUZIQI_QI_ZI_H
