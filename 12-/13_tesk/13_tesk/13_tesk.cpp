#include<iostream>
#include<vector>
#include<initializer_list>
#include"13_tesk.h"

using namespace std;

//struct X {
//	X() { cout << "X()" << endl; }
//	X(const X&) { cout << "X(const X&)" << endl; }
//	X& operator=(const X&) { cout << "X& operator=(const X&)" << endl; return *this; }
//	~X() { cout << "~X()" << endl; }
//
//};

//void f(const X &rx, X x) {
//	vector<X> v;
//	v.reserve(2);
//	v.push_back(rx);
//	v.push_back(x);
//}

//class numbered {
//public:
//	numbered() { mysn = unique++; }
//	numbered(const numbered& n) { mysn = unique++; }
//
//	int mysn;
//	static int unique;
//};
//int numbered::unique = 10;
//
//void f(numbered& s) {
//	std::cout << s.mysn << std::endl;
//}
int main()
{
	/*X *px = new X;
	f(*px, *px);
	delete px;*/
	/*numbered a, b = a, c = b;
	f(a); f(b); f(c);*/

	return 0;
}