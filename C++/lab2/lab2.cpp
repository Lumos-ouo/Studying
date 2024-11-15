#include<iostream>
#include<iomanip>
using namespace std;
/*定义结构数组*/
struct students{
    char name[20];
    int score[10]={0};
    /*假设共有10门课程*/
    float average;
};
int main(){
    students lists[1000];
    int num,i,j,MaxNum,MinNum,courses,id;
    int scores;
    cin >>num;
    for(i=0;i<num;i++){
        /*输入数据*/
        cin >> lists[i].name;
        courses=0;
        scores=0;
        for(j=0;j<11;j++){
        cin >> id;
        if(id==-1){
            break;
        }
        /*-1 表示输入结束*/
        
        cin >> lists[i].score[id-101];
        scores+=lists[i].score[id-101];
        courses+=1;
        }
        /*计算平均值*/
        lists[i].average=scores/(courses*1.0);
    }
    float average[10];
    for(i=0;i<10;i++){
        scores=0;
        courses=0;
        for(j=0;j<num;j++){
            if(lists[j].score[i]!=0){
                 courses+=1;
            }
            scores+=lists[j].score[i];  
        }
        average[i]=scores/(courses*1.0);
        /*计算课程平均分*/
    }   
    int min[10],max[10];
    /*找出科目的最大值和最小值*/
    for(i=0;i<10;i++){
        MaxNum=1;
        MinNum=5;
        for(j=0;j<num;j++){
        if(lists[j].score[i]>MaxNum){
            MaxNum=lists[j].score[i];
        }
        if (lists[j].score[i]<MinNum && lists[j].score[i]!=0){
            MinNum=lists[j].score[i];
        }
        }
        max[i]=MaxNum;
        min[i]=MinNum;
    }
    /*输出结果，注意格式即可*/
    cout << left << setw(8) <<"no"<< left <<setw(8) <<"name"<< left ;
    for ( i = 0; i < 10; i++)
    {
       cout <<"score" << left << setw(3) <<i+1;
    }
    cout << left << setw(8) <<"average"<< endl;
    for(i=0;i<num;i++){
        cout << left << setw(8) << i+1 << left << setw(8) << lists[i].name;
        for(j=0;j<10;j++){
            if(lists[i].score[j]>0){
            cout << left << setw(8) << lists[i].score[j];
            }
            else{
            cout << left << setw(8) << "NULL";
            }
        }
        cout << left << setw(8) << lists[i].average << endl;
    }
    /*输出平均值*/
    cout <<"        average ";
    for ( i = 0; i < 10; i++)
    {
        cout << left << setw(8) << average[i];
    }
    /*输出最小值*/
    cout << endl;
    cout <<"        min     ";
    for ( i = 0; i < 10; i++)
    {
        cout << left << setw(8) << min[i];
    }
    /*输出最大值*/
    cout << endl;
    cout <<"        max     ";
    for ( i = 0; i < 10; i++)
    {
        cout << left << setw(8) << max[i];
    }
    return 0;
}
