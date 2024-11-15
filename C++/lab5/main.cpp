#include"Fraction.h"
Fraction conversion(string s);
int main(){
    Fraction f1;
    Fraction f2(3,4);       //构造函数传参
    Fraction f3(f2);        //拷贝构造函数
    cin>>f1;
    cout<<f1;
    //测试运算符重载
    f3=f1+f2;
    cout<<f3;
    f3=f1-f2;
    cout<<f3;
    f3=f1*f2;
    cout<<f3;
    f3=f2/f1;
    cout<<f3;
    //测试关系运算符重载
    cout<<(f1==f2)<<endl;
    cout<<(f1!=f2)<<endl;
    cout<<(f1>f2)<<endl;
    cout<<(f1<f2)<<endl;
    cout<<(f1>=f2)<<endl;
    cout<<(f1<=f2)<<endl;
    //测试转换函数
    double a=toDouble(f1);
    cout<<a<<endl;
    string s=toString(f1);
    cout<<s<<endl;
    f1=conversion("3.14159");
    cout<<f1;
    return 0;
}