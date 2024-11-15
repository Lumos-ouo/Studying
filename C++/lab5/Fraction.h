#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
#include<string>
using namespace std;
class Fraction
{
private:
    int n;      //定义分子
    int d;      //定义分母
public:
    //默认构造函数
    Fraction(){
    }
    //自定义构造函数
    Fraction(int n,int d){
        this->n=n;
        this->d=d;
        cout<<"Ctor"<<endl;
    }
    //拷贝构造函数
    Fraction(const Fraction &f){
        n=f.n;
        d=f.d;
        cout<<"Copy Ctor"<<endl;
    }
    //友元函数声明
    friend Fraction operator+ (Fraction &f1,Fraction &f2);
    friend Fraction operator- (Fraction &f1,Fraction &f2);
    friend Fraction operator* (Fraction &f1,Fraction &f2);
    friend Fraction operator/ (Fraction &f1,Fraction &f2);
    friend bool operator< (Fraction &f1,Fraction &f2);
    friend bool operator<= (Fraction &f1,Fraction &f2);
    friend bool operator== (Fraction &f1,Fraction &f2);
    friend bool operator!= (Fraction &f1,Fraction &f2);
    friend bool operator>= (Fraction &f1,Fraction &f2);
    friend bool operator> (Fraction &f1,Fraction &f2);
    friend double toDouble(Fraction &f);
    friend string toString(Fraction &f);
    friend void operator<<(ostream& cout, Fraction &f);
    friend void operator>>(istream& cin, Fraction &f);
};
#endif