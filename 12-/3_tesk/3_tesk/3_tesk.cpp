#include<iostream>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
//void show(vector<int> v);
template<typename T>
void show(T v)
{
	/*auto s1 = v.size();
	cout << s1 << endl;
	for (auto i : v)
		cout << i << endl;*/
	
	for (auto iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << endl;
};
bool compare(int *const pb1, int *const pe1, int *const pb2, int *const pe2)
{
	if ((pe1 - pb1) != (pe2 - pb2))
		return false;
	else {
		for (int *i = pb1, *j = pb2; i != pe1; i++, j++)
			if (*i != *j)return false;
	}
	return true;
}

int main()
{
//3.2.2½ÚÁ·Ï°
	/*string s;
	while (getline(cin, s))
		cout << s << endl;*/
		/*string a;

		for(int i = 0;i < 10; i++)
		{
			cin >>a;
			cout << a << endl;
		}*/

		/*string s1, s2;
		cin >> s1 >> s2;
		if (s1 == s2)
			cout << "equal" << endl;
		else if (s1 > s2)
			cout << "s1 larger" << endl;
		else cout << "s2 larger" << endl;*/

		/*string total;
		if (cin >> total)
		{
			string trans;
			while (cin >> trans)
			{
				total += trans;
				cout << total << endl;
			}
		}
		cout << total << endl;*/

//3.2.3½ÚÁ·Ï°
		/*string s = "asfjlkjfjffjl";
			for (auto &c : s)
			{
				if (isalpha(c))
					c = 'X';
				cout << c << endl;
			}
		cout << s << endl;*/
		/*string s = "asfjlkjfjffjl";
		for (char &c : s)
		{
			if (isalpha(c))
				c = 'X';
			cout << c << endl;
		}
		cout << s << endl;*/
		/*string s = "asfjlkjfjffjl";
		auto n = s.size();
		int i = 0;
		while (i < n)
		{
			if (isalpha(s[i]))
				s[i] = 'X';
			cout << s << endl;
			i++;
		}
		cout << s << endl;*/
		/*string s;
		while (cin >> s)
		{
			for (auto &c : s)
			{
				if (ispunct(c)) continue;
				else cout << c;
			}
		}*/

//3.3.3½ÚÁ·Ï°
	/*vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{ 10 };
	vector<int> v5{ 10,42 };
	vector<string> v6{ 10 };
	vector<string> v7{ 10,"hi" };
	show(v1); show(v2); show(v3); show(v4); show(v5);
	show(v6); show(v7);*/
	/*vector<string> s;
	string word;
	while (cin >> word)
		s.push_back(word);
	for (auto &i : s)
		for (auto &c : i)
			c = toupper(c);
	show(s);*/

	/*vector<int> ivec;
	int i;
	while (cin >> i)
		ivec.push_back(i);
	if (ivec.empty())
	{
		cout << "input at least one integer." << endl;
		return -1;
	}
	else if (ivec.size() == 1)
	{
		cout << ivec[0] << " dont have any adjacent element" << endl;
	}
	else {
		for (decltype (ivec.size()) i = 0; i != ivec.size() - 1; i++)
			cout << ivec[i] + ivec[i + 1] << " ";
	}
	cout << endl;*/
    /*vector<int> n{ 0,1,2,3,4,5,6,7,8,9 };
	for (auto it = n.begin(); it != n.end(); it++)
		*it *= 2;
	show(n);*/
    
//3.5.2½ÚÁ·Ï°
	/*int ia[10];
	for (size_t i = 0; i < 10; i++)
		ia[i] = i;
	for (auto a : ia)
	cout << a << " ";
	cout << endl;*/
    /*int ia[10];
	for (size_t i = 0; i < 10; i++)
		ia[i] = i;
	int ia2[10];
	for (size_t i = 0; i < 10; i++)
		ia2[i] = ia[i];
	for (auto a : ia2)
		cout << a << " ";

	vector<int> iv(10);
	for (auto iter = iv.begin(); iter != iv.end(); iter++)
		*iter = iter - iv.begin();
	show(iv);
	vector<int> iv2 = iv;
	show(iv2);*/
 
	/*unsigned scores[11] = {};
	unsigned grade;
	while ( cin >> grade){
		if (grade <= 100)
			++scores[grade / 10];
	}
	for (auto i : scores)
	cout << i << " ";
	cout << endl;*/

//3.5.3½ÚÁ·Ï°
	/*int ia[10];
	for (size_t i = 0; i < 10; i++)
		ia[i] = i;
	int *pbeg = begin(ia);
	int *pend = end(ia);
	while (pbeg != pend && *pbeg >= 0) {
		*pbeg = 0;
		++pbeg;
	}
	for (auto a : ia)
		cout << a << " ";*/
	/*int a[4] = { 1,2,4,6 };
	int b[4] = { 1,2,5,6 };
	if (compare(begin(a), end(a), begin(b), end(b)))
	cout << " equal" << endl;
	else
	cout << " not equal" << endl;

	vector<int> a1 = { 1,2,4,5 };
	vector<int> b1 = { 1,2,3,4 };
	if (a1 == b1)
	cout << " equal" << endl;
	else cout << " not equal" << endl;*/

//3.5.4½ÚÁ·Ï°
	/*const char ca[] = { 'h','e','l','l','o','\0' };
	const char sa[] = "world";
	const char *cp = ca;
	while (*cp) {
		cout << *cp << endl;
		++cp;
	}*/
	/*string s1 = "liwenjian";
	string s2 = "liwenjian";
	if (s1 < s2)
		cout << "false" << endl;
	else cout << "equal" << endl;
	 char ca1[] = "liwenjian";
	const char ca2[] = "liwenjian";
	int result = strcmp(ca1, ca2);
	cout << result << endl;*/

int a1[] = { 0,1,2,3,4,5 };
vector<int> v1(begin(a1), end(a1));
show(v1);
int a2[6];
for (int* i = begin(a2); i != end(a2); i++)
*i = v1[i - begin(a2)];
for (auto a : a2)
cout << a << " ";
cout << endl;
	return 0;
}
