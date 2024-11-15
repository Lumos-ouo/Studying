#include<iostream>
#include"Diary.h"
int main(){
    string data, entity,line;
    entity="";
    cout << "Enter data: ";
    cin >> data;
    cout << "Enter entity: ";
    while(getline(cin, line)){
        if(line =="."){
            break;
        }
        entity += line + '\n';
    }
    int i=0;
    for(i= 0;i<366;i++){
        if(diaries[i].getData()==data){
            diaries[i].set(data,entity);
            break;
        }
        else if(diaries[i].getData()==""){
            diaries[i].set(data,entity);
            break;
        }
    }
    return 0;
}