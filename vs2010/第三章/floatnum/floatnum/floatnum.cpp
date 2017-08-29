// floatnum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;
	cout.setf(ios_base::fixed,ios_base::floatfield);   //fixed-point
	float tub = 10.0/3.0;
	double mint = 10.0/3.0;
	const float Million = 1.0e6;

	cout << "tub = " << tub;
	cout << ",a million tub = " << Million * tub<<endl;
	cout << "and ten million tub = " << 10 * Million * tub <<endl;

	cout << "mint = " << mint;
	cout << ",a million mint = " << Million * mint << endl;

	return 0;
}

