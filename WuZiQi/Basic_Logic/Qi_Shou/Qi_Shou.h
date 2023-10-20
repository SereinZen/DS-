#ifndef WUZIQI_QI_SHOU_H
#define WUZIQI_QI_SHOU_H

class location_double;

class Qi_Shou {
private:
    location_double *loc;//鼠标点击后的x、y坐标
    //还需完成鼠标控制部分的内容
public:
    Qi_Shou();//构造函数
    ~Qi_Shou();//析构函数
    void play();//走棋函数
};


#endif //WUZIQI_QI_SHOU_H
