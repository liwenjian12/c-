#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<deque>
#include<forward_list>
#include"9_tesk.h"
using namespace std;

template<typename T>
void show(T &v)
{
	for (auto a : v)
		cout << a << " ";
	cout << endl;
}


void insert(forward_list<string> &flst, string find, string insrt)
{
	auto prev = flst.before_begin();
	for (auto curr = flst.begin(); curr != flst.end(); prev = curr++)
		if (*curr == find)
		{
			flst.insert_after(curr, insrt);
			return;
		}
	flst.insert_after(prev, insrt);
}


void swap(string &s, const string &oldVal, const string &newVal)
{
	auto curr = s.begin();
	while (curr != (s.end() - oldVal.size()))
	{
		if (oldVal == string(curr, curr + oldVal.size()))
		{
			curr = s.erase(curr, curr + oldVal.size());
			curr = s.insert(curr, newVal.begin(), newVal.end());
			curr += newVal.size();
		}
		else
		{
			++curr;
		}
	}
}

int main()
{
	/*list<int> ilst(5, 4);
	show(ilst);
	vector<int> ivc(5, 5);
	show(ivc);

	vector<double>dvc(ilst.begin(), ilst.end());
	show(dvc);
	vector<double>dvc2(ivc.begin(), ivc.end());
	show(dvc2);
	list<const char*> l{ "hello","world" };
	show(l);
	vector<string>v;
	v.assign(l.cbegin(), l.cend());
	show(v);*/

	/*vector<int> v1{ 1,2,3,4,5 };
	vector<int>v2{ 1,2,3,4,5 };
	vector<int>v3{ 1,2,3,4 };
	cout << (v1 == v2) ? "true" : "false" ;
	cout << endl;
    cout << (v1 == v3) ? "true" : "false" ;
	cout << endl;
	list<int>li{ 1,2,3,4,5 };
	cout <<( vector<int>(li.begin(), li.end()) == v2 ? "true" : "false")<<endl;
	cout << (vector<int>(li.begin(), li.end()) == v3 ? "true" : "false")<<endl;*/
	
	/*deque<string> de;
	string s;
	while (cin >> s)de.push_back(s);
	for (deque<string>::const_iterator iter = de.begin();
		iter != de.end(); ++iter)
		cout << *iter << " ";
	cout << endl;*/

	/*deque<int> de1;
	deque<int> de2;
	list<int> li1;
	int i;
	while (cin >> i)li1.push_back(i);
	show(li1);
	for (list<int>::const_iterator iter = li1.begin(); iter != li1.end(); ++iter)
	{
		if ((*iter )% 2) de2.push_back(*iter);
		else de1.push_back(*iter);
	}
	show(de1);
	show(de2);*/

	/*vector<int> v;
	cout << v.at(0);
	cout << v[0];
	cout << v.front();
	cout << *v.begin();*/

	/*int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };
	vector<int> v1(ia, end(ia));
	list<int> li(v1.begin(), v1.end());
	for (auto iter = v1.begin(); iter != v1.end();)
	{
		if (*iter & 0x1) iter = v1.erase(iter);
		else ++iter;
	}
	for (auto iter = li.begin(); iter != li.end();)
	{
		if (!(*iter & 0x1))iter = li.erase(iter);
		else ++iter;
	}
	show(v1);
	show(li);*/

	/*forward_list<int> flt = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flt.before_begin();
	auto curr = flt.begin();
	while (curr != flt.end())
	{
		if ((*curr) & 0x1)curr = flt.erase_after(prev);
		else prev = curr++;
	}
	show(flt);*/

	/*vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		cout << "capacity: " << v.capacity() << " size: " << v.size() << endl;
		v.push_back(i);
	}*/

	/*vector<char> v{ 'l','e','e','w'};
	string s(v.cbegin(), v.cend());
	show(v);
	cout << s << endl;*/

	/*string s("TO drive straigt thru is a foolish ,tho courageous act.");
	swap(s, "tho", "though");
	swap(s, "thru", "through");
	cout << s << endl;*/

	//string name("huang");
	//cout << add_pre_and_suffix(name, "Mr.", "Jr.") << endl;
	return 0;
}