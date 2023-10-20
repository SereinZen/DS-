#ifndef WUZIQI_QI_ZI_H
#define WUZIQI_QI_ZI_H

class Qi_Pan;
class Qi_Shou;
class location;

class Qi_Zi {
private:
    location *loc;
    int clickValid();
public:
    Qi_Zi();
    ~Qi_Zi();
    int Luo_Zi();
};


#endif //WUZIQI_QI_ZI_H
