// Test.cpp : �������̨Ӧ�ó������ڵ㡣
//a example shows conbination of classes

#include "stdafx.h"
#include <iostream>
using namespace std;
class Point  //��������
{
public:
	Point(int xx,int yy){X=xx;Y=yy;}   //���캯��(��ʼ��)
	Point(Point &p);                   //�������캯��
	int GetX(void)   {return X;}       //ȡX���꣨�������캯����
	int GetY(void)   {return Y;}
private:
	int X,Y;                           //�������
};
Point::Point(Point &p)               //��ĳ�Ա�����ⲿ����
{
	X = p.X;
	Y = p.Y;
	cout<<"Point�������캯��������"<<endl;
}
class Distance  //����������
{
public:
	Distance(Point a,Point b);     //���캯��
	double GetDis() {return dist;}
private:
	Point p1,p2;                    
    double dist;                    //����
};
// �����Ĺ��캯��
Distance::Distance(Point a,Point b):p1(a),p2(b)
{
	cout<<"Distance���캯��������"<<endl;
	double x = double(p1.GetX()-p2.GetX());
	double y = double(p1.GetY()-p2.GetY());
	dist = sqrt(x*x+y*y);
	return;
}

int _tmain(int argc, _TCHAR* argv[])
{
 Point myp1(1,1),myp2(4,5);       //������Point�͵ĺ���myp,����ʼ��
 Distance myd(myp1,myp2);        //������Distance�͵ĺ���myd,������ʼ
 cout<<"The distance is:";        
 cout<<myd.GetDis()<<endl;
   return 0;
}
