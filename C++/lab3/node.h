//node类
#ifndef NODE_H
#define NODE_H
#include<string>
using namespace std;
class node
    {
    public:
        //初始化坐标
        int x=0; 
        int y=0;   
        //根据指令进行移动 
        void move(string s);
    };
#endif