//node类的函数实现
#include "node.h"
void node::move(string s){
    //根据不同指令进行坐标变化
            if(s=="go up"){
                y=y+1;
            }
            if(s=="go down"){
                y=y-1;
            }
            if(s=="go west"){
                x=x-1;
            }
            if(s=="go east"){
                x=x+1;
            }
            return;
        }