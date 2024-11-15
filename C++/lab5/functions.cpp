#include<math.h>
#include<algorithm>
#include"Fraction.h"
//重载“+”
Fraction operator+ (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3.n=f1.n*f2.d+f2.n*f1.d;
    f3.d=f1.d*f2.d;
    return f3;
}
//重载“-”
Fraction operator- (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3.n=f1.n*f2.d-f2.n*f1.d;
    f3.d=f1.d*f2.d;
    return f3;
}
//重载“*”
Fraction operator* (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3.n=f1.n*f2.n;
    f3.d=f1.d*f2.d;
    return f3;
}
//重载“/”
Fraction operator/ (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3.n=f1.n*f2.d;
    f3.d=f1.d*f2.n;
    return f3;
}
//重载“<”
bool operator< (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)<0;
}
//重载“<=”
bool operator<= (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)<=0;
}
//重载“==”
bool operator== (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)==0;
}
//重载“!=”
bool operator!= (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)!=0;
}
//重载“>=”
bool operator>= (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)>=0;
}
//重载“>”
bool operator> (Fraction &f1,Fraction &f2)
{
    Fraction f3;
    f3=f1-f2;
    return (f3.n*f3.d)>0;
}
//转换为double
double toDouble(Fraction &f){
    double a;
    a=1.0*f.n/f.d;
    return a;
}
//转换为string
string toString(Fraction &f){
    string s;
    s=to_string(f.n)+"/"+to_string(f.d);
    return s;
}
//重载输出流
void operator<<(ostream &cout,Fraction &f){
    int a;
    //约分
    a=__gcd(abs(f.n),abs(f.d));
    f.n=f.n/a;
    f.d=f.d/a;
    //对于负数进行处理
    if(f.n*f.d<0){
        cout<<"-";
    }
    //对分子为0进行处理
    if (f.n==0)
    {
        cout<<"0"<<endl;
    }
    //对整数进行处理
    else if (abs(f.d)==1)
    {
        cout<<abs(f.n)<<endl;
    }
    //分母为0的非法输入
    else if (f.d==0)
    {
        cout<<"Error"<<endl;
    }
    else{
    cout<<abs(f.n)<<"/"<<abs(f.d)<<endl;}
}
//重载输入流
void operator>>(istream &cin, Fraction &f){
    cin>>f.n;
    if(getchar()=='/'){
        cin>>f.d;
    }
    else{
        f.d=1;
    }
}
//将字符串转换为分数
Fraction conversion(string s){
    double a;
    a=stod(s);
    int b=1;
    while(a-int(a)){
        a=a*10;
        b=b*10;
    }
     Fraction f1(int(a),b);
     return f1;
}