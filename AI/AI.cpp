#include "AI.h"
#include <limits>
#include <iostream>
#include <ctime>

using namespace std;

// AI 类的实现
AI::AI() {
    qiPan = nullptr;
    pos = new location(0,0);
    a = nullptr;
}
AI::~AI(){
    delete pos;
    if(a){
        for(int i=0;i<qiPan->getSize();i++){
            if(a[i]){
                delete []a[i];
            }
        }
        delete []a;
    }
    if(qiPan){
        delete qiPan;
    }
}
void AI::set(Qi_Pan *qiPan) {
    this->qiPan = qiPan;
    a=new int*[qiPan->getSize()];
    for(int i=0;i<qiPan->getSize();i++){
        a[i]=new int[qiPan->getSize()];
        for(int j=0;j<qiPan->getSize();j++){
            a[i][j]=qiPan->getQiPan()[i][j];
        }
    }
}

int AI::isWin(int color,location loc){
    if (qiPan->getLoc() == nullptr){
        return 0;
    }
    int size=qiPan->getSize();
    int x=loc.getX();
    int y=loc.getY();

    //判定平局
    if(qiPan->getRest()==0){
        return 2;
    }

    //水平方向
    for(int i=0;i<5;i++) {
        if (y - i >= 0 && y - i + 4 < size
            && color == a[x][y - i]
            && color == a[x][y - i + 1]
            && color == a[x][y - i + 2]
            && color == a[x][y - i + 3]
            && color == a[x][y - i + 4]) {
            std::cout<<"水平方向"<<std::endl;
            return color;
        }
    }

    //竖直方向
    for(int i=0;i<5;i++) {
        if (x - i >= 0 && x - i + 4 < size
            && color == a[x - i][y]
            && color == a[x - i + 1][y]
            && color == a[x - i + 2][y]
            && color == a[x - i + 3][y]
            && color == a[x - i + 4][y]) {
            std::cout<<"竖直方向"<<std::endl;
            return color;
        }

    }

    //右斜方向
    for(int i=0;i<5;i++) {
        if (x - i >= 0 && y - i >= 0
            && x - i + 4 < size && y - i + 4 < size
            && color == a[x - i][y - i]
            && color == a[x - i + 1][y - i + 1]
            && color == a[x - i + 2][y - i + 2]
            && color == a[x - i + 3][y - i + 3]
            && color == a[x - i + 4][y - i + 4]) {
            std::cout<<"右斜方向"<<std::endl;
            return color;
        }
    }

    //左斜方向
    for(int i=0;i<5;i++) {
        if (x+i<size && x+i-4>=0
            && y-i>=0 && y-i+4<size
            && color == a[x + i][y - i]
            && color == a[x + i - 1][y - i + 1]
            && color == a[x + i - 2][y - i + 2]
            && color == a[x + i - 3][y - i + 3]
            && color == a[x + i - 4][y - i + 4]) {
            std::cout<<"左斜方向"<<std::endl;
            return color;
        }
    }
    return 0;
}

void AI::getScore(int color,string line){
    int size=qiPan->getSize();

    //活四
    for(int k=0;k<3;k++){
        if(line.contains("0++++0")){
            int first=line.find("0++++0");
            line[first+1]='#';
            line[first+2]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curHuoSi++;
            }
            else{
                oppHuoSi++;
            }

        }
    }
    //冲四
    for(int k=0;k<3;k++){
        if((line.contains("0++++-") || line.contains("-++++0"))){
            int first=0;
            if(line.contains("0++++-")){
                first=line.find("0++++-");
            }
            if(line.contains("-++++0")){
                first=line.find("-++++0");
            }
            line[first+1]='#';
            line[first+2]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curChongSi++;
            }
            else{
                oppChongSi++;
            }
        }
        if(line.contains("++0++")){
            int first=line.find("++0++");
            line[first]='#';
            line[first+1]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curChongSi++;
            }
            else{
                oppChongSi++;
            }
        }
        if(line.contains("+0+++")){
            int first=line.find("+0+++");
            line[first]='#';
            line[first+2]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curChongSi++;
            }
            else{
                oppChongSi++;
            }
        }
        if(line.contains("+++0+")){
            int first=line.find("+++0+");
            line[first]='#';
            line[first+1]='#';
            line[first+2]='#';
            line[first+4]='#';
            if(color==-1){
                curChongSi++;
            }
            else{
                oppChongSi++;
            }
        }
    }
    //活三
    for(int k=0;k<3;k++){
        if(line.contains("0++++0")){
            int first=line.find("0++++0");
            line[first+1]='#';
            line[first+2]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curHuoSan++;
            }
            else{
                oppHuoSan++;
            }
        }
        if(line.contains("+0++")){
            int first=line.find("+0++");
            line[first]='#';
            line[first+2]='#';
            line[first+3]='#';
            if(color==-1){
                curHuoSan++;
            }
            else{
                oppHuoSan++;
            }
        }
        if(line.contains("++0+")){
            int first=line.find("++0+");
            line[first]='#';
            line[first+1]='#';
            line[first+3]='#';
            if(color==-1){
                curHuoSan++;
            }
            else{
                oppHuoSan++;
            }
        }
    }
    //眠三
    for(int k=0;k<3;k++){
        if(line.contains("00+++0") || line.contains("-0+++0-")){
            int first=0;
            if(line.contains("00+++0")){
                first=line.find("00+++0");
            }
            if(line.contains("-0+++0-")){
                first=line.find("-0+++0-");
            }
            line[first+2]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("0+++00")){
            int first=line.find("0+++00");
            line[first+1]='#';
            line[first+2]='#';
            line[first+3]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("0+0++0") || line.contains("-+0++0")){
            int first=0;
            if(line.contains("0+0++0")){
                first=line.find("0+0++0");
            }
            if(line.contains("-+0++0")){
                first=line.find("-+0++0");
            }
            line[first+1]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("0++0+0") || line.contains("0++0+-")){
            int first=0;
            if(line.contains("0++0+0")){
                first=line.find("0++0+0");
            }
            if(line.contains("0++0+-")){
                first=line.find("0++0+-");
            }
            line[first+1]='#';
            line[first+2]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("+00++")){
            int first=line.find("+00++");
            line[first]='#';
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("++00+")){
            int first=line.find("++00+");
            line[first]='#';
            line[first+1]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
        if(line.contains("+0+0+")){
            int first=line.find("+0+0+");
            line[first]='#';
            line[first+2]='#';
            line[first+4]='#';
            if(color==-1){
                curMianSan++;
            }
            else{
                oppMianSan++;
            }
        }
    }
    //活二
    for(int k=0;k<3;k++){
        if(line.contains("00++00")){
            int first=line.find("00++00");
            line[first+2]='#';
            line[first+3]='#';
            if(color==-1){
                curHuoEr++;
            }
            else{
                oppHuoEr++;
            }
        }
        if(line.contains("0+0+0")){
            int first=line.find("0+0+0");
            line[first+1]='#';
            line[first+3]='#';
            if(color==-1){
                curHuoEr++;
            }
            else{
                oppHuoEr++;
            }
        }
        if(line.contains("+00+")){
            int first=line.find("+00+");
            line[first]='#';
            line[first+3]='#';
            if(color==-1){
                curHuoEr++;
            }
            else{
                oppHuoEr++;
            }
        }
    }
    //眠二
    for(int k=0;k<3;k++){
        if(line.contains("000++-")){
            int first=line.find("000++-");
            line[first+3]='#';
            line[first+4]='#';
            if(color==-1){
                curMianEr++;
            }
            else{
                oppMianEr++;
            }
        }
        if(line.contains("-++000")){
            int first=line.find("-++000");
            line[first+1]='#';
            line[first+2]='#';
            if(color==-1){
                curMianEr++;
            }
            else{
                oppMianEr++;
            }
        }
        if(line.contains("0+00+-") || line.contains("-+00+0") || line.contains("0+00+-") || line.contains("-+00+0")){
            int first=0;
            if(line.contains("0+00+-")){
                first=line.find("0+00+-");
            }
            if(line.contains("-+00+0")){
                first=line.find("-+00+0");
            }
            if(line.contains("0+00+-")){
                first=line.find("0+00+-");
            }
            if(line.contains("-+00+0")){
                first=line.find("-+00+0");
            }
            line[first+1]='#';
            line[first+4]='#';
            if(color==-1){
                curMianEr++;
            }
            else{
                oppMianEr++;
            }
        }
        if(line.contains("+000+")){
            int first=line.find("+000+");
            line[first]='#';
            line[first+4]='#';
            if(color==-1){
                curMianEr++;
            }
            else{
                oppMianEr++;
            }
        }
    }
    //单子
    for(int k=0;k<3;k++){
        if(line.contains("00+00") || line.contains("0-+00") || line.contains("00+-0")){
            int first=0;
            if(line.contains("0+0")){
                first=line.find("0+0");
            }
            if(line.contains("-+0")){
                first=line.find("-+0");
            }
            if(line.contains("0+-")){
                first=line.find("0+-");
            }
            line[first+1]='#';
            if(color==-1){
                curSingle++;
            }
            else{
                oppSingle++;
            }
        }
    }
    //TODO debug
//

}

int AI::evaluateScore(int color,int minX,int minY,int maxX,int maxY) {
    int curScore = 0;
    int oppScore = 0;
    curChongSi = 0;
    oppChongSi = 0;
    curHuoSi = 0;
    oppHuoSi = 0;
    curHuoSan = 0;
    oppHuoSan = 0;
    curMianSan = 0;
    oppMianSan = 0;
    curHuoEr = 0;
    oppHuoEr = 0;
    curMianEr = 0;
    oppMianEr = 0;
    curSingle = 0;
    oppSingle = 0;

    //遍历当前每颗棋子，统计评分
    for(int i=0;i<qiPan->getSize();i++){
        for(int j=0;j<qiPan->getSize();j++){
            if(a[i][j]!=0){
                location loc(i,j);
                //必杀情况1 己方胜利，直接返回10000分
                if(color==isWin(color,loc)){
                    cout<<"必杀情况1 己方胜利，直接返回100000分"<<endl;
                    return 100000;
                }
                //必杀情况2 如果对手连五，直接返回-10000分
                if(-color==isWin(-color,loc)){
                    cout<<"必杀情况2 如果对手连五，直接返回-10000分"<<endl;
                    return -10000;
                }

                string line1="";
                string line2="";
                //水平方向
                for(int x=0;x<qiPan->getSize();x++){
                    for(int y=0;y<qiPan->getSize();y++){
                        if(color==a[x][y]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[x][y]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[x][y]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    getScore(color,line1);
                    getScore(-color,line2);
                    line1="";
                    line2="";
                }
                //竖直方向
                line1="";
                line2="";
                for(int x=0;x<qiPan->getSize();x++){
                    for(int y=0;y<qiPan->getSize();y++){
                        if(color==a[y][x]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[y][x]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[y][x]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    getScore(color,line1);
                    getScore(-color,line2);
                    line1="";
                    line2="";
                }
                line1="";
                line2="";
                //TODO 斜向
                //右斜上半
                for(int x=qiPan->getSize()-1;x>=0;x--){
                    for(int y=0;x+y<qiPan->getSize();y++){
                        if(color==a[x+y][y]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[x+y][y]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[x+y][y]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    if(line1.length()>=5){
                        getScore(color,line1);
                    }
                    if(line2.length()>=5){
                        getScore(-color,line2);
                    }
                    line1="";
                    line2="";
                }
                line1="";
                line2="";
                //右斜下半
                for(int x=qiPan->getSize()-1;x>0;x--){
                    for(int y=0;x+y<qiPan->getSize();y++){
                        if(color==a[y][x+y]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[y][x+y]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[y][x+y]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    if(line1.length()>=5){
                        getScore(color,line1);
                    }
                    if(line2.length()>=5){
                        getScore(-color,line2);
                    }
                    line1="";
                    line2="";
                }
                line1="";
                line2="";
                //左斜上半
                for(int x=0;x<qiPan->getSize();x++){
                    for(int y=0;x-y>=0;y++){
                        if(color==a[x][x-y]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[x][x-y]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[x][x-y]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    if(line1.length()>=5){
                        getScore(color,line1);
                    }
                    if(line2.length()>=5){
                        getScore(-color,line2);
                    }
                    line1="";
                    line2="";
                }
                line1="";
                line2="";
                //左斜下半
                for(int x=1;x<qiPan->getSize();x++){
                    for(int y=0;x+y<qiPan->getSize();y++){
                        if(color==a[x+y][x-y]){
                            line1+="+";
                            line2+="-";
                        }
                        if(-color==a[x+y][x-y]){
                            line1+="-";
                            line2+="+";
                        }
                        if(0==a[x+y][x-y]){
                            line1+="0";
                            line2+="0";
                        }
                    }
                    if(line1.length()>=5){
                        getScore(color,line1);
                    }
                    if(line2.length()>=5){
                        getScore(-color,line2);
                    }
                    line1="";
                    line2="";
                }

                //必杀情况3 对手两个冲四当做1个活四处理（直接返回-9050分）
                if(oppChongSi>=2){
                    return -9050;
                }
                //必杀情况4 对手活四，直接返回-9050分
                if(oppHuoSi>=1){
                    return -9050;
                }
                //必杀情况5 对手冲四，直接返回-9040分
                if(oppChongSi>=1){
                    return -9040;
                }
                //必杀情况6 己方活四，直接返回9030分
                if(curHuoSi>=1){
                    return 9030;
                }
                //必杀情况7 己方有冲四以及活三，直接返回9020分
                if(curChongSi>=1 && curHuoSan>=1){
                    return 9020;
                }
                //必杀情况8 己方没有冲四，且对方有活三，直接返回9010分
                if(curChongSi==0 && oppHuoSan>=1){
                    return 9010;
                }
                //必杀情况9 己方有2个活三，对方没有活三以及眠三，直接返回9000分
                if(curHuoSan>=2 && oppHuoSan==0 && oppMianSan==0){
                    return 9000;
                }

                //TODO 评分细则优化
                if(curChongSi>0){
                    curScore+=2000;
                }

                if(curHuoSan>1){
                    curScore+=500;
                }
                else if(curHuoSan>0){
                    curScore+=100;
                }

                if(oppHuoSan>1){
                    oppScore+=2000;
                }
                else if(oppHuoSan>0){
                    oppScore+=400;
                }

                if(curMianSan>0){
                    curScore+=curMianSan*10;
                }
                if(oppMianSan>0){
                    oppScore+=oppMianSan*10;
                }

                if(curHuoEr>0){
                    curScore+=curHuoEr*4;
                }
                if(oppHuoEr>0){
                    oppScore+=oppHuoEr*4;
                }

                if(curMianEr>0){
                    curScore+=curMianEr*4;
                }
                if(oppMianEr>0){
                    oppScore+=oppMianEr*4;
                }

                //TODO debug
//                cout<<"白棋活四："<<curHuoSi<<endl;
//                cout<<"白棋冲四："<<curChongSi<<endl;
//                cout<<"白棋活三："<<curHuoSan<<endl;
//                cout<<"白棋眠三："<<curMianSan<<endl;
//                cout<<"白棋活二："<<curHuoEr<<endl;
//                cout<<"白棋眠二："<<curMianEr<<endl;
//                cout<<"白棋单子："<<curSingle<<endl;
//                cout<<"白棋当前分数："<<curScore<<endl;
//
//                cout<<"黑棋活四："<<oppHuoSi<<endl;
//                cout<<"黑棋冲四："<<oppChongSi<<endl;
//                cout<<"黑棋活三："<<oppHuoSan<<endl;
//                cout<<"黑棋眠三："<<oppMianSan<<endl;
//                cout<<"黑棋活二："<<oppHuoEr<<endl;
//                cout<<"黑棋眠二："<<oppMianEr<<endl;
//                cout<<"黑棋单子："<<oppSingle<<endl;
//                cout<<"黑棋当前分数："<<oppScore<<endl;
            }
        }
    }

    return curScore - oppScore;
}

location* AI::evaluate(){
    int score[qiPan->getSize()][qiPan->getSize()];
    int minX=0;
    int minY=0;
    int maxX=qiPan->getSize();
    int maxY=qiPan->getSize();
    int maxScore = -10000;
    int count=0;
    for(int i=0;i<qiPan->getSize();i++){
        for(int j=0;j<qiPan->getSize();j++){
            a[i][j]=qiPan->getQiPan()[i][j];
            score[i][j]=-10000;
        }
    }
    for(int i=0;i<qiPan->getSize();i++){
        for(int j=0;j<qiPan->getSize();j++){
            if(a[i][j]!=0){
                count++;
                minX=i;
                break;
            }
        }
        if(count!=0){
            break;
        }
    }
    count=0;
    for(int i=0;i<qiPan->getSize();i++){
        for(int j=0;j<qiPan->getSize();j++){
            if(a[j][i]!=0){
                count++;
                minY=i;
                break;
            }
        }
        if(count!=0){
            break;
        }
    }
    count=0;
    for(int i=qiPan->getSize()-1;i>=0;i--){
        for(int j=qiPan->getSize()-1;j>=0;j--){
            if(a[i][j]!=0){
                count++;
                maxX=i;
                break;
            }
        }
        if(count!=0){
            break;
        }
    }
    count=0;
    for(int i=qiPan->getSize()-1;i>=0;i--){
        for(int j=qiPan->getSize()-1;j>=0;j--){
            if(a[j][i]!=0){
                count++;
                maxY=i;
                break;
            }
        }
        if(count!=0){
            break;
        }
    }
    if(minX!=0){
        minX--;
    }
    if(minY!=0){
        minY--;
    }
    if(maxX!=qiPan->getSize()-1){
        maxX++;
    }
    if(maxY!=qiPan->getSize()){
        maxY++;
    }
    //将棋盘局限在了(minX,minY)与(maxX,maxY)中间，减少遍历范围
    for(int i=minX;i<=maxX;i++){
        for(int j=minY;j<=maxY;j++){
            if(a[i][j]==0){
                a[i][j]=-1;
                score[i][j]= evaluateScore(-1,minX,minY,maxX,maxY);
                a[i][j]=0;
                if(maxScore==score[i][j]){
                    srand((unsigned)time(NULL));
                    int num=rand()%100 +1;
                    if(num<30){
                        maxScore=score[i][j];
                        pos->set(qiPan->getChessSize()+j*(qiPan->getGap()+1),qiPan->getChessSize()+i*(qiPan->getGap()+1));
                    }
                }
                if(maxScore<score[i][j]){
                    maxScore=score[i][j];
                    pos->set(qiPan->getChessSize()+j*(qiPan->getGap()+1),qiPan->getChessSize()+i*(qiPan->getGap()+1));
                }
            }
        }
    }

//    //TODO debug
    for(int i=0;i<qiPan->getSize();i++){
        for(int j=0;j<qiPan->getSize();j++){
            cout<<score[i][j]<<" ";
        }
        cout<<endl;
    }

    return pos;
}

location* AI::getBestMove() {
    return evaluate();
}