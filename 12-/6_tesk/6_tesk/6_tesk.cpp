#include<iostream>
#include<string>
#include<vector>
#include<initializer_list>
#include<iterator>
#include"Chapter6.h"
using namespace std;
template<typename T>
void show(T v)
{
	for (auto a : v)
		cout << a << " ";
	cout << endl;
};


//6.1½ÚÁ·Ï°

int fact(int n)
{
	int result = 1;
	for (int n1 = n; n1 != 0; --n1)
		result *= n1;
	return result;
}
void cal(void)
{
	int a;
	while (cin >> a) {
		int b = fact(a);
		cout << b << endl;
	}
}
int count_add()
{
	//static size_t ctr = 0;
	static int count = 0;

	return count++;
}
void swap(int &a, int &b)
{
	int c = a;
    a = b;
	b = c;
}
void swap_ptr(int* &p1, int* &p2)
{
	int *temp = p1;
	p1 = p2;
	p2 = temp;
}
void reset(int &i)
{
	i = 0;
}
int compare1(const int a,const int *b)
{
	return a > *b ? a : *b;
}
int initial_add(initializer_list<int> li)
{
	int add = 0;
	for (auto a : li)
		add += a;
	return add;
}
//bool str_subrange(const string &str1, const string &str2)
//{
//	if (str1.size() == str2.size())
//		return str1 == str2;
//	auto size = (str1.size() < str2.size())
//		? str1.size() : str2.size();
//	for (decltype(size)i = 0; i != size; ++i) {
//		if (str1[i] != str2[i])
//			return ;
//	}
//
//}

template<typename T>
void show1(const vector<T> &v)
{
	static
		typename vector<T>::const_iterator it = v.begin();
	cout << *it << " " << endl;
	++it;
	if(it!=v.end())
	{
		show1(v);
	}
}

string make_plural(size_t ctr, string &word, const string ending="s")
{
	return(ctr > 1) ? word + ending : word;
}
inline bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}
inline int action(const int, const int);
typedef decltype(action) fp;

inline  int numadd(const int a, const int b) { return a + b; }
inline  int numsub(const int a, const int b) { return a - b; }
inline  int nummul(const int a, const int b) { return a * b; }
inline  int numdiv(const int a, const int b) { return a / b; }

vector <fp*> v{ numadd,numsub,nummul,numdiv };
int main()
{
	//cal();
	//int a,b,c;
	//cin >> a >>b;
	////cout << abs(a) << " "<< b;
	//cout << endl;
	//swap(a, b);
	/*cout << a << " " << b << endl;
	c = compare1(a, &b);
	cout << c << endl;*/
	//reset(a); reset(b);
	//cout << a << " " << b << endl;

   //for (size_t i = 0; i != 10; ++i)
		//cout << count_add() << endl;
	/*int a, b;
	int* p1 = &a, *p2 = &b;
	while (cin >> a >> b) {
		p1 = &a, p2 = &b;
		swap_ptr(p1,p2);
		cout << *p1 << " " << *p2 << "\n";
	}*/
	/*int b = initial_add({ 3, 5, 6, 7, 8, 9 });
	cout << b << endl;*/

	//6.3.2½ÚÁ·Ï°
	/*string s1, s2;
	cin >> s1 >> s2;
	bool t = str_subrange(s1, s2);
	cout << t << endl;*/
	/*string s;
	vector<string> v;
	while(cin>>s)
	{
		v.push_back(s);
	}
	show1(v);*/
	
	/*string s1 = "success", s2 = "failure";
	cout << make_plural(1, s1) << endl;
	cout << make_plural(1, s2) << endl;
	cout << make_plural(2, s1) << endl;
	cout << make_plural(2, s2) << endl;*/

	//cout << isShorter("money", "liwenjian") << endl;

	for (vector<fp*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)(2, 2)  // here shows how to use it!
			<< std::endl;
	}
	return 0;
}