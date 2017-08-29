// Practice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void ufck(int x)
{
	cout<<x<<endl;
}
void(*show_pointer)(int a );

int _tmain(int argc, _TCHAR* argv[])
{
	int a=10;
	show_pointer=ufck;
	show_pointer(a);
	return 0;   
}

