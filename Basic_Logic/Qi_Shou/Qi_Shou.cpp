#include "Qi_Shou.h"
#include "..\Qi_Pan\Qi_Pan.h"
#include "..\Qi_Zi\Qi_Zi.h"
#include "..\Game\Game.h"

Qi_Shou::Qi_Shou(){
    loc=new location_double(0,0);
}

Qi_Shou::~Qi_Shou(){
    delete loc;
}

void Qi_Shou::play() {
    /*
        内容与步骤：
        允许鼠标点击
        等待点击
        获取鼠标点击坐标并保存
        禁用鼠标
        调用Qi_Zi的落子函数，传参当前颜色与x、y坐标
     */
}