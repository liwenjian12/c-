// typecast.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	int auks,bats,coots;

	auks = 10.99 + 19.99;

	bats = (int)19.99 + (int)10.99;
	coots = int (19.99) + int (10.99);
	cout << "auks = " << auks << endl;
	cout << "bats = " << bats <<endl;
	cout << "coots = " << coots <<endl;

	char ch = 'Z';
	cout << "The code for "<< ch << " is " <<int(ch) <<endl;
	cout << "Yes, the code is ";
	cout << static_cast<int>(ch) <<endl;
	return 0;
}

