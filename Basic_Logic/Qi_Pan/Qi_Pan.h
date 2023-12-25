#ifndef WUZIQI_QI_PAN_H
#define WUZIQI_QI_PAN_H
#include <SFML/Graphics.hpp>
#include "../Qi_Zi/Qi_Zi.h"

class location;
class Qi_zi;

class Qi_Pan {
private:
    int size;//棋盘尺寸
    int width; // 棋盘的宽度
    int height; // 棋盘的高度
    int dotRadius; // 背景图 五个定位点 的半径
    int chessRadius; // 棋子的半径
    int **qiPan;// 棋盘数组
    sf::RenderTexture* renderTexture; // 纹理
    int gap; // 棋盘中线条的间距
    int rest;// 棋盘中剩余空位的数量
    location* myLoc; //当前棋子的数组坐标
    location* chessLoc; //当前棋子的实际坐标
    void generateWuZiQiBackground();
    Qi_Zi* qiZi;
public:
    Qi_Pan(int width, int height, int dotRadius, int qiRadius, sf::RenderTexture* renderTexture);//构造函数
    ~Qi_Pan();//析构函数
    int color;// 当前棋子颜色
    int getSize();//返回棋盘尺寸
    int getChessSize();//返回棋子大小
    int **getQiPan();//返回棋盘数组
    void update(location* loc);//接收更新棋盘数据
    int getColor();//返回当前棋子颜色
    int getRest();//返回剩余空位数量
    int getGap();//返回棋盘线条间距
    location* getChessLoc();//返回棋子实际坐标
    location* getLoc();//返回棋子下标坐标
    void set(Qi_zi* qiZi);
    sf::RenderTexture* getBackGround();
    void set(Qi_Zi *qiZi);
};


#endif //WUZIQI_QI_PAN_H
