#include<iostream>
#include<string>
#include<vector>
using namespace std;
template <typename T>
void show(T v)
{
	for (auto a : v)
		cout << a << " ";
	cout << endl;
};
int main()
{
	//4.2½ÚÁ·Ï°
	/*int a;
	while (cin >> a)
	{
		if (a % 2)
			cout << a << "Ææ" << endl;
		else cout << a << "Å¼" << endl;
	}*/
	/*short svalue = 32767; ++svalue; cout << svalue << endl;
	unsigned uivalue = 0; --uivalue; cout << uivalue << endl;
	unsigned short usvalue = 65535; cout << ++usvalue << endl;*/
	/*int a;
	while (cin >> a) {
		cout << a << endl;
		if (a == 42)
			break;
		else continue;
	}*/
	/*vector<int> a;
	int b;
	while (cin >> b)
		a.push_back(b);
	for (auto iter = a.begin(); iter != a.end(); ++iter)
	{
		*iter % 2 ? *iter *= 2 : *iter = *iter ;
		continue;
	}
	show(a);*/
	/*unsigned grade;
	while (cin >> grade)
		cout << ((grade > 90) ? "high pass" :
		(grade < 60) ? "fail" :
			(grade < 75) ? "low pass" : "pass");*/
	cout << "bool\t\tis"       << sizeof(bool)        << " bytes." << endl;
	cout << "char\t\tis"       << sizeof(char)        << " bytes." << endl;;
	cout << "wchar_t\t\tis"    << sizeof(wchar_t)     << " bytes." << endl;;
	cout << "char16_t\t\tis"   << sizeof(char16_t)    << " bytes." << endl;;
	cout << "char32_t\t\tis"   << sizeof(char32_t)    << " bytes." << endl;;
	cout << "short\t\tis"      << sizeof(short)       << " bytes." << endl;;
	cout << "int\t\tis"        << sizeof(int)         << " bytes." << endl;;
	cout << "long\t\tis"       << sizeof(long)        << " bytes." << endl;;
	cout << "long long\t\tis"  << sizeof(long long)   << " bytes." << endl;;
	cout << "float\t\tis "     << sizeof(float)       << " bytes." << endl;
	cout << "double\t\tis "    << sizeof(double)      << " bytes." << endl;
	cout << "long double\tis " << sizeof(long double) << " bytes." << endl;
	cout << endl;
	int x[10]; int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
	return 0;
}
