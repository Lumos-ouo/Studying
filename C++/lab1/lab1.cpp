#include<iostream>
#include<iomanip>
using namespace std;
/*定义结构数组*/
struct students{
    char name[20];
    int score1;
    int score2;
    int score3;
    float average;
};
int main(){
    students lists[10];
    int i,j,MaxNum,MinNum;
    for(i=0;i<10;i++){
        /*输入数据*/
        cin >> lists[i].name;
        cin >> lists[i].score1;
        cin >> lists[i].score2;
        cin >> lists[i].score3;
        /*计算平均值*/
        lists[i].average=(lists[i].score1+lists[i].score2+lists[i].score3)/3.0;
    }
    int min[3],max[3],sum1=0,sum2=0,sum3=0;
    float a[3];
    for(i=0;i<10;i++){
        sum1+=lists[i].score1;
        sum2+=lists[i].score2;
        sum3+=lists[i].score3;
    }
    /*计算三个科目的平均值*/
    a[0]=sum1/10.0;
    a[1]=sum2/10.0;
    a[2]=sum3/10.0;
    MaxNum=lists[0].score1;
    MinNum=lists[0].score1;
    /*找出三个科目的最大值和最小值*/
    for(i=0;i<10;i++){
        if(lists[i].score1>MaxNum){
            MaxNum=lists[i].score1;
        }
        if (lists[i].score1<MinNum){
            MinNum=lists[i].score1;
        }
    }
    /*存放score1*/
    max[0]=MaxNum;
    min[0]=MinNum;
    MaxNum=lists[0].score2;
    MinNum=lists[0].score2;
    for(i=0;i<10;i++){
        if(lists[i].score2>MaxNum){
            MaxNum=lists[i].score2;
        }
        if (lists[i].score2<MinNum){
            MinNum=lists[i].score2;
        }
    }
    /*存放score2*/
    max[1]=MaxNum;
    min[1]=MinNum;
    MaxNum=lists[0].score3;
    MinNum=lists[0].score3;
    for(i=0;i<10;i++){
        if(lists[i].score3>MaxNum){
            MaxNum=lists[i].score3;
        }
        if (lists[i].score3<MinNum){
            MinNum=lists[i].score3;
        }
    }
    /*存放score3*/
    max[2]=MaxNum;
    min[2]=MinNum;
    /*输出结果，注意格式即可*/
    cout<<left<<setw(8)<<"no"<<left<<setw(8)<<"name"<<left<<setw(8)<<"score1";
    cout<<left<<setw(8)<<"score2"<<left<<setw(8)<<"score3"<<left<<setw(7)<<"average"<<endl;
    for(i=0;i<10;i++){
        cout<<left<<setw(8)<<i+1<<left<<setw(8)<<lists[i].name<<left<<setw(8)<<lists[i].score1;
        cout<<left<<setw(8)<<lists[i].score2<<left<<setw(8)<<lists[i].score3<<left<<setw(7)<<lists[i].average<<endl;
    }
    cout<<"        average "<<left<<setw(8)<<a[0]<<left<<setw(8)<<a[1]<<left<<setw(8)<<a[2]<<endl;
    cout<<"        min     "<<left<<setw(8)<<min[0]<<left<<setw(8)<<min[1]<<left<<setw(8)<<min[2]<<endl;
    cout<<"        max     "<<left<<setw(8)<<max[0]<<left<<setw(8)<<max[1]<<left<<setw(8)<<max[2]<<endl;
    return 0;

}
