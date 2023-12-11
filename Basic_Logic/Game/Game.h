#ifndef WUZIQI_GAME_H
#define WUZIQI_GAME_H
#include <SFML/Graphics.hpp>
//#define draw 0
//#define nonOver 2
#define black 1;
#define white -1;

class Qi_Pan;
class Qi_Shou;
class Qi_Zi;

class location{
private:
    int x;
    int y;
public:
    location(int a,int b);
    location* getLoc();
    void set(int a,int b);
    int getX();
    int getY();
};

class Game {
private:
    Qi_Pan *qiPan;//棋盘指针
    Qi_Shou *qiShou;//棋手指针
    Qi_Zi *qiZi;//棋子指针
    sf::RenderWindow* window; // 窗口
    sf::Sprite* sprite; // 画好的面板
    sf::RenderTexture* renderTexture;//?
    sf::Event event;//窗口全局监听事件

public:
    Game(int width, int height, int dotRadius, int Qi_radius);//构造函数，创建游戏
    ~Game();//析构函数，删除指针
    int victory();//判断是否分出胜负函数
    void play();//控制游戏流程函数
};


#endif //WUZIQI_GAME_H
