#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
#include"10_tesk.h"
//#include"ex7_26.h"

using namespace std;
template<typename T>
void show(T const  &v) 
{
	for (auto &a : v)
		cout << a << " ";
	cout << endl;
}

void elimdups(vector<string> &vs)
{
	sort(vs.begin(), vs.end());
	auto new_end = unique(vs.begin(), vs.end());
	vs.erase(new_end, vs.end());
}

void biggies(vector<string> &vs, size_t sz)
{
	elimdups(vs);
	stable_sort(vs.begin(), vs.end(),
		[](string const& lhs, string const& rhs) {
		return lhs.size() < rhs.size(); }
	);
	auto wc = find_if(vs.begin(), vs.end(),
		[sz](string const& s) {return s.size() >= sz; }
	);

	for_each(wc, vs.end(),
		[](const string &s) {
		cout << s << " ";}
	);
}

bool predicate(const string &s)
{
	return s.size() >= 5;
}

int main()
{
	/*list<string> li ;
	ifstream in("liwenjian.txt");
	string s;
	while (in >> s) li.push_back(s);
	for (auto &a :li)cout << a << " ";
	cout << endl;
	cout << count(li.cbegin(), li.cend(), "wo") << endl;*/

	/*vector<double> v;
	ifstream in("liwen.txt");
	int a;
	while (in >> a)v.push_back(a);
	int sum;
	cout<< (sum = accumulate(v.cbegin(), v.cend(), 0))<<endl;*/

	/*vector<int> v;
	ifstream in("liwen.txt");
	int a;
	while (in >> a)v.push_back(a);
	show(v);
	fill_n(v.begin(), v.size(), 0);
	show(v);*/

	/*vector<string> vs;
	ifstream in("liwenjian.txt");
	string a;
	while (in >> a)vs.push_back(a);
	println(vs);
	println(eliminate_duplicates(vs));*/

	/*vector<string> vs;
	ifstream in("liwenjian.txt");
	string a;
	while (in >> a)vs.push_back(a);
	elimdups(vs);
	stable_sort(vs.begin(), vs.end(), is_shorter);
	cout << "ex10.11:\n";
	println(vs);*/

	/*auto v = vector<string>{ "a","as","aasss","aaaaass","aaaaaabba","aaa" };
	auto pivot = partition(v.begin(), v.end(), predicate);
	for (auto it = v.cbegin(); it != pivot; ++it)
		cout << *it << " ";
	cout << endl;*/

	std::vector<std::string> v
	{
		"1234", "1234", "1234", "hi~", "alan", "alan", "cp"
	};
	std::cout << "ex10.16: ";
	biggies(v, 3);
	std::cout << std::endl;
	return 0;
}