#ifndef WUZIQI_QI_PAN_H
#define WUZIQI_QI_PAN_H
#include <SFML/Graphics.hpp>

class location;

class Qi_Pan {
private:
    int size;//棋盘尺寸
    int width; // 棋盘的宽度
    int height; // 棋盘的高度
    int dotRadius; // 背景图 五个定位点 的半径
    int QiRadius; // 棋子的半径
    int color;
    int **qiPan;// 棋盘数组
    sf::RenderTexture* renderTexture; // 纹理
    int gap; // 棋盘中线条的间距
    int rest;
    location* myloc;
    location* qiloc;
    void generateWuZiQiBackground();

public:
    Qi_Pan(int width, int height, int dotRadius, int qiRadius, sf::RenderTexture* renderTexture);//构造函数
    ~Qi_Pan();//析构函数
    int getSize();//返回棋盘尺寸
    int getChessSize();//返回棋子大小
    int **getQiPan();//返回棋盘数组
    void update(location* loc);//接收更新棋盘数据
    int getColor();
    int getRest();
    int getGap();
    location* getqiloc();
    location* getLoc();
    int clickValid(location* loc);
    sf::RenderTexture* getBackGround();
};


#endif //WUZIQI_QI_PAN_H
