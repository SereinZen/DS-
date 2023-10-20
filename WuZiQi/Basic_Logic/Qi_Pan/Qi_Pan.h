#ifndef WUZIQI_QI_PAN_H
#define WUZIQI_QI_PAN_H

class location;

class Qi_Pan {
private:
    int size;//���̳ߴ�
    location *loc;//���һ�ӵ�x��y����
    int color;//���һ�ӵ���ɫ
    int chessSize;//���Ӵ�С
    int **qiPan;//��������
public:
    Qi_Pan();//���캯��
    ~Qi_Pan();//��������
    int getSize();//�������̳ߴ�
    location* getLoc();//�������һ��x��y����
    int getColor();//�������һ����ɫ
    int getChessSize();//�������Ӵ�С
    int **getQiPan();//������������
    void getChessPicture(location *loc);//��ʾ����ͼƬ��Ҫ�жϵ�ǰ�Ǻڻ��ǰף�
    void update(int color,int **qiPan,location *loc);//���ո�����������
    void display();//��ʼ����������
};


#endif //WUZIQI_QI_PAN_H
