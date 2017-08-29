// getingo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	char ch = 'M';
	int i = ch;
	cout <<"The ASCII code for "<< ch << " is "<<i<<endl;

	cout << "Add one to the character code :"<<endl;
	ch = ch+1;
	i = ch;
	cout << "The ASCII code for "<< ch <<" is "<<i<<endl;

	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);

	cout.put('!');
	cout<< endl <<"Done"<<endl;

	
	return 0;
}

