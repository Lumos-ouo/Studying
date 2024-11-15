//初始化函数
#include<string.h>
#include<cstdlib> // 用于随机数生成
#include<ctime> 
#include"room.h" 
using namespace std;
void initialize(Room rooms[]){
        rooms[0].num=1;
        rooms[0].name="Room1";
        rooms[0].exits[0]="east";
        rooms[0].x=-1;
        rooms[0].y=0;
        rooms[0].flag=0;
        rooms[1].num=3;
        rooms[1].name="lobby";
        rooms[1].exits[0]="east";
        rooms[1].exits[1]="west";
        rooms[1].exits[2]="up";
        rooms[1].x=0;
        rooms[1].y=0;
        rooms[1].flag=0;
        rooms[2].num=2;
        rooms[2].name="Room2";
        rooms[2].exits[0]="east";
        rooms[2].exits[1]="west";
        rooms[2].x=1;
        rooms[2].y=0;
        rooms[2].flag=0;
        rooms[3].num=2;
        rooms[3].name="Room3";
        rooms[3].exits[0]="west";
        rooms[3].exits[1]="up";
        rooms[3].x=2;
        rooms[3].y=0;
        rooms[3].flag=0;
        rooms[4].num=2;
        rooms[4].name="Room4";
        rooms[4].exits[0]="east";
        rooms[4].exits[1]="up";
        rooms[4].x=-1;
        rooms[4].y=1;
        rooms[4].flag=0;
        rooms[5].num=3;
        rooms[5].name="Room5";
        rooms[5].exits[0]="east";
        rooms[5].exits[1]="west";
        rooms[5].exits[2]="down";
        rooms[5].x=0;
        rooms[5].y=1;
        rooms[5].flag=0;
        rooms[6].num=3;
        rooms[6].name="Room6";
        rooms[6].exits[0]="east";
        rooms[6].exits[1]="west";
        rooms[6].exits[2]="up";
        rooms[6].x=1;
        rooms[6].y=1;
        rooms[6].flag=0;
        rooms[7].num=2;
        rooms[7].name="Room7";
        rooms[7].exits[0]="west";
        rooms[7].exits[1]="down";
        rooms[7].x=2;
        rooms[7].y=1;
        rooms[7].flag=0;
        rooms[8].num=2;
        rooms[8].name="Room8";
        rooms[8].exits[0]="east";
        rooms[8].exits[1]="down";
        rooms[8].x=-1;
        rooms[8].y=2;
        rooms[8].flag=0;
        rooms[9].num=2;
        rooms[9].name="Room9";
        rooms[9].exits[0]="east";
        rooms[9].exits[1]="west";
        rooms[9].x=0;
        rooms[9].y=2;
        rooms[9].flag=0;
        rooms[10].num=3;
        rooms[10].name="Room10";
        rooms[10].exits[0]="east";
        rooms[10].exits[1]="west";
        rooms[10].exits[2]="down";
        rooms[10].x=1;
        rooms[10].y=2;
        rooms[10].flag=0;
        rooms[11].num=1;
        rooms[11].name="Room11";
        rooms[11].exits[0]="west";
        rooms[11].x=2;
        rooms[11].y=2;
        rooms[11].flag=0;
        int arr[] = {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        int len = 11;
        // 初始化随机数生成器
        srand(time(0));
        // 选择第一个随机元素
        int index1 = rand() % len;
        // 选择第二个随机元素，确保与第一个不同
        int index2 = index1;
        while (index2 == index1) {
            index2 = rand() % len;
        }
        int element1 = arr[index1];
        int element2 = arr[index2];
        rooms[element1].flag=1;   //表示princess
        rooms[element2].flag=-1;   //表示monster
    return;
}