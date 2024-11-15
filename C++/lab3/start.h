//“开始游戏”函数
#include<iostream>
#include<string.h>
#include"room.h"
#include"node.h"
void start(node player ,string command, Room rooms[12]){
    int i,n;
    n=0;
    while(1){
            //输入命令
            getline(cin,command);
            //进行移动
            player.move(command);
            //判断目前所处房间
            for(i=0;i<12;i++){
                if(rooms[i].x==player.x&&rooms[i].y==player.y){
                    break;
                }
            }
            //找到公主并返回lobby
            if(n==1 && i==1){
                cout<<"You return the lobby with the princess successfully and you win the game!" <<endl;
                break;
            }
            //进入房间
            if(rooms[i].flag==0){
                cout<<"Welcome to "<<rooms[i].name<<". There are "<<rooms[i].num<<" exits: ";
                if(rooms[i].num==1){
                    cout<<rooms[i].exits[0]<<".";
                }
                else if(rooms[i].num==2){
                    cout<<rooms[i].exits[0]<<" and "<<rooms[i].exits[1]<<".";
                }
                else{
                    cout<<rooms[i].exits[0]<<", " << rooms[i].exits[1]<<" and " << rooms[i].exits[2]<<".";
                }
                cout<<" Enter your command:" << endl;
            }
            //找到princess
            else if(rooms[i].flag==1){
                n=1;
                cout<<"You have found the princess." << endl;
                cout<<"Princess: Thank you. Take me to the lobby, and we leave here."<<endl;
                cout<<"I: OK!"<<endl;
                cout<<"There are "<<rooms[i].num<<" exits: ";
                if(rooms[i].num==1){
                    cout<<rooms[i].exits[0]<<". ";
                }
                else if(rooms[i].num==2){
                    cout<<rooms[i].exits[0]<<" and "<<rooms[i].exits[1]<<". ";
                }
                else{
                    cout<<rooms[i].exits[0]<<", " << rooms[i].exits[1]<<" and " << rooms[i].exits[2]<<". ";
                }
                cout<<"Enter your command:" << endl;           
            }
            //遇到monster，游戏结束
            else if(rooms[i].flag==-1){
                cout<<"You have found the monster room. You lose!" << endl ;
                break;
            }
        }
}