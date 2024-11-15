#include<iostream>
#include<string.h>
//导入相关头文件
#include"room.h" 
#include"node.h"
#include"start.h"
using namespace std;
int main(){
        Room rooms[12]; //Room类
        node player;  //node类
        string command;  //指令
        initialize(rooms);  //rooms初始化
        cout << "Welcome to the lobby. There are 3 exits: east, west and up. Enter your command:" << endl;
        start(player,command,rooms); //开始游戏
        return 0;
    }


