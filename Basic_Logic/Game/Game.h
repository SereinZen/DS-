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

class location_double{
private:
    int x;
    int y;
public:
//    location_double(int a,int b);
    location_double* getLoc();
//    void set(int a,int b);
    int getX();
    int getY();
};

class Game {
private:
    Qi_Pan *qiPan;
    Qi_Shou *qiShou;
    Qi_Zi *qiZi;
    sf::RenderWindow* window; // 窗口
    sf::Sprite* sprite; // 画好的面板
    sf::RenderTexture* renderTexture;

public:
    Game(int width, int height, int dotRadius, int Qi_radius);
    ~Game();
    int victory();
    void play();
};


#endif //WUZIQI_GAME_H
