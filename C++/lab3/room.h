//Room类
#ifndef ROOM_H
#define ROOM_H
#include<string>
using namespace std;
class Room
    {
    public:
        int num;  //房间数量
        string name;   //房间名字
        string exits[4];  //出口
        int flag;  //房间类别
        int x;   //房间的位置坐标
        int y;
    };
void initialize(Room rooms[]);
#endif