// 3.7practice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	/*
	//第一题
	int height;
	const int Trans = 12;
	cout << "Enter your height in inch ：____\b\b\b\b ";
	cin  >>height;
	float foot = (float)height / Trans ;
	cout << "Your height in inch is : " << height <<endl;
	cout << "Your height in foot is : " << foot   <<endl;
	*/

	
	/*
	//第二题
	int foot,inch,pound;
	cout << "Enter your height in foots and inchs : ___\b\b\b  foots   ___\b\b\b inchs .\n";
	cin  >> foot >> inch;
	cout << "Enter your weight in pounds:____\b\b\b\b pounds.\n";
	cin  >> pound;
	const int Trans1 =12 ;
	
	const double Trans2 = 2.2  ,  Trans3= 0.0254;
	double  metre = foot * Trans1 * Trans3 + inch * Trans3;
	double kilogram = (double)pound / Trans2;
	double BMI = pow(kilogram,2);
	cout << "Your height in metre : " <<metre <<" metre"<<",your weight in kilogram : "<<kilogram <<" kilogram."<<endl;
	cout << "Your BMI is : "<< BMI<<endl;
	*/


	/*
	//第三题
	int degrees,minutes,seconds;
	const int Trans = 60;
	cout <<"Enter a latitude in degrees,minutes,and seconds : \n";
	cout <<"First,enter the degrees: ____\b\b\b\b ";
	cin  >>degrees ;
	cout <<endl;
	cout <<"Next,enter the minutes of arc : _____\b\b\b\b";
	cin  >>minutes;
	cout <<endl;
	cout <<"Finally,enter the seconds of arc : ____\b\b\b\b";
	cin  >>seconds;
	cout <<endl;


	float t_minutes = (float)minutes/Trans;
	float t_seconds = (float)seconds/Trans/Trans;
    float t_degrees = degrees + t_minutes +t_seconds;
	cout <<degrees <<" degrees" <<minutes <<",minutes" <<seconds <<",seconds";
	cout <<" = "<<t_degrees << " degrees." <<endl;
	*/

	
	/*
	//第四题
	int seconds;
	cout << "Enter the number of seconds : _____\b\b\b\b";
	cin  >>seconds;
	const int trans1 = 60,trans2 = 24;
	int days = seconds / (trans2 * trans1 * trans1);
	int rest1 = seconds % (trans2 *trans1 * trans1) ;
	int hours = rest1 / (trans1 * trans1);
	int rest2 = rest1 % (trans1 * trans1);
	int minutes = rest2 / trans1;
	int rest3 = rest2 % trans1;
	int rest_seconds = rest3 ;
	cout <<seconds <<" seconds = "<< days << " days ,"<<hours << " hours , ";
	cout <<minutes <<" minutes ," <<rest3 <<" seconds.";
	*/

	/*
	//第五题
    long long w_popu ,a_popu;
	cout.setf(ios_base::fixed,ios_base::floatfield);
	cout <<"world popu : ";cin >> w_popu;
	cout <<"amer  popu : ";cin >> a_popu;

    float per = ( float)a_popu /(float)w_popu;
	cout <<per ;
	*/
	return 0;
}

