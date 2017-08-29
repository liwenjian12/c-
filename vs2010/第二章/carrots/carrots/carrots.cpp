// carrots.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	int carrots;
	carrots = 25;
	cout<<"I have "<<carrots<<" carrots."<<endl;
	carrots-=1;
	cout<<"Crunch,crunch,now I have "<<carrots<<" carrots"<<endl;
	return 0;
}

