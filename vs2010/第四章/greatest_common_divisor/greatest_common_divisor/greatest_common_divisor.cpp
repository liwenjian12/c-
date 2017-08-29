// greatest_common_divisor.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
int result(int x,int y);

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	int num1,num2,divisor;
	cout << "Enter two unsigned integers : " <<endl;
	cin  >>num1;
	cin  >>num2;

	if (num1 >=num2)divisor =  result( num1,num2);
	else divisor = result( num2,num1);
	cout << "greatest common divisor is : " << divisor <<endl;

	return 0;
}

int result (int x,int y)
{
	int z = x % y;
	if (z == 0) return y;
	else  result (y,z);
	
}
