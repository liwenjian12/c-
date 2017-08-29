// string.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "Howdy! I'm " << name2;
	cout << "! What's your name ?\n";
	cin  >> name1;
	cout << "Well,"<< name1 <<",your name have ";
	cout << strlen(name1) << " letters and is stored "<<endl;
	cout << "in array of " << sizeof(name1) << " bytes.\n";
	cout << "Your initial is "<< name1[0] << ".\n";
	name2[3] = '\0';                                           //set to null character
	cout << "Here are the first 3 letters of my name ：" << name2 <<endl;
	return 0;
}

