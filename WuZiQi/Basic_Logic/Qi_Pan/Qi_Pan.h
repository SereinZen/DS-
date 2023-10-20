#ifndef WUZIQI_QI_PAN_H
#define WUZIQI_QI_PAN_H

class location;

class Qi_Pan {
private:
    int size;//棋盘尺寸
    location *loc;//最后一子的x、y坐标
    int color;//最后一子的颜色
    int chessSize;//棋子大小
    int **qiPan;//棋盘数组
public:
    Qi_Pan();//构造函数
    ~Qi_Pan();//析构函数
    int getSize();//返回棋盘尺寸
    location* getLoc();//返回最后一子x、y坐标
    int getColor();//返回最后一子颜色
    int getChessSize();//返回棋子大小
    int **getQiPan();//返回棋盘数组
    void getChessPicture(location *loc);//显示棋子图片（要判断当前是黑还是白）
    void update(int color,int **qiPan,location *loc);//接收更新棋盘数据
    void display();//初始化，画棋盘
};


#endif //WUZIQI_QI_PAN_H
