// Test.cpp : 定义控制台应用程序的入口点。
//a example shows conbination of classes

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point  //构造点的类
{
public:
	Point(int xx,int yy){X=xx;Y=yy;}   //构造函数(初始化)
	Point(Point &p);                   //拷贝构造函数
	int GetX(void)   {return X;}       //取X坐标（内联构造函数）
	int GetY(void)   {return Y;}
private:
	int X,Y;                           //点的坐标
};
Point::Point(Point &p)               //类的成员函数外部定义
{
	X = p.X;
	Y = p.Y;
	cout<<"Point拷贝构造函数被调用"<<endl;
}
class Distance  //构造距离的类
{
public:
	Distance(Point a,Point b);     //构造函数
	double GetDis() {return dist;}
private:
	Point p1,p2;                    
    double dist;                    //距离
};
// 组合类的构造函数
Distance::Distance(Point a,Point b):p1(a),p2(b)
{
	cout<<"Distance构造函数被调用"<<endl;
	double x = double(p1.GetX()-p2.GetX());
	double y = double(p1.GetY()-p2.GetY());
	dist = sqrt(x*x+y*y);
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
 Point myp1(1,1),myp2(4,5);       //定义了Point型的函数myp,并初始化
 Distance myd(myp1,myp2);        //定义了Distance型的函数myd,并初化始
 cout<<"The distance is:";        
 cout<<myd.GetDis()<<endl;
   return 0;
}
