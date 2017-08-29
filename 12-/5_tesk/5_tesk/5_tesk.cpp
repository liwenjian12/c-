#include<iostream>
#include<string>
#include<vector>
using namespace std;
template<typename T>
void show(T v)
{
	for (auto a : v)
		cout << a << " ";
	cout << endl;
};
int main()
{
	//5.3.1½ÚÁ·Ï°
	/*vector<string> scores = { "F","D","C","B","A","A++" };
	int grade{ 0 };
	while (cin >> grade) {
		string lettergrade;
		if (grade < 60)
			lettergrade = scores[0];
		else {
			lettergrade = scores[(grade - 50) / 10];
			if (grade != 100)
			{
				if (grade % 10 > 7)
					lettergrade += "+";
				else if (grade % 10 < 3)
					lettergrade += "-";
			}

		}
		cout << lettergrade << endl;
	}*/
	/*vector<string> scores = { "F","D","C","B","A","A++" };
	int grade(0);
	while (cin >> grade) {
		string lettergrade;
		(grade < 60) ? lettergrade = scores[0] : lettergrade = scores[(grade - 50) / 10],
			(grade % 10 > 7) ? lettergrade += "+" : (grade % 10 < 3) ? lettergrade += "-" :lettergrade=lettergrade ;
		cout << lettergrade << endl;
		
	}*/
	/*unsigned acnt = 0, icnt = 0, ocnt = 0, ecnt = 0, ucnt = 0;
	char ch;
	while (cin >> ch) {
		if (ch == 'a'||ch=='A')++acnt;
		else if (ch == 'i'||'I')++icnt;
		else if (ch == 'o' || 'O')++ocnt;
		else if (ch == 'e'||'E')++ecnt;
		else if (ch == 'u'||'U')++ucnt;
	}
	cout << "number of 'a'" << acnt << endl;
	cout << "number of 'i'" << icnt << endl;
	cout << "number of 'o'" << ocnt << endl;
	cout << "number of 'e'" << ecnt << endl;
	cout << "number of 'u'" << ucnt << endl;*/
	/*unsigned ffcnt = 0, flcnt = 0, ficnt = 0;
	char ch1,ch2;
	while (cin >> ch1)
		if (ch1 == 'f')
			while (cin >> ch2) {
				if (ch2 == 'f')++ffcnt;
				else if (ch2 == 'l')++flcnt;
				else if (ch2 == 'i')++ficnt;
				else break;
			}
		else continue;
		cout << ffcnt << endl
			<< flcnt << endl 
			<<ficnt << endl;*/
	/*
	pair <string, int> max_duplicated;
	int count = 0;
	for (string str, prestr; cin >> str; prestr = str)
	{
		if (str == prestr) ++count;
		else count = 0;
		if (count > max_duplicated.second)max_duplicated = { prestr,count };
	}
	if (max_duplicated.first.empty()) cout << "There's no duplicated string" << endl;
	else cout << "the word" << max_duplicated.first << " occurred " << max_duplicated.second + 1 << "times." << endl;*/

	/*vector<int>v1, v2;
	int i;
	while (cin >> i &&i!='00')
		v1.push_back(i);
	while (cin >> i)
		v2.push_back(i);
	show(v1); show(v2);
	auto size = v1.size() < v2.size() ? v1.size() : v2.size();
	for (int j = 0; j != size; ++j) {
		if (v1[j] == v2[j])continue;
		else {
			cout << "no pre-" << endl; break;
		}
	}
	cout << "true" << endl;*/
	/*string rsp;
	do {
		cout << "Enter two strings" << endl;
		string s1, s2;
		cin >> s1 >> s2;
		cout << (s1.size() < s2.size() ? s1 : s2)
			<< "is shorter" << endl
			<< "more? y or n" << endl;
		cin >> rsp;
	} while (!rsp.empty() && rsp[0]=='y');*/
	/*string s1, s2="\0";
	while (cin >> s1) {
		if (s1 == s2)break;
		else s2 = s1;	
	}
	if (cin.eof())cout << "no word was repeted" << endl;
	else cout << s1 << endl;*/
    /*int a, b;
	cin >> a >> b;
	if (b == 0)
		throw runtime_error("divisor is zero ");
	cout << static_cast<double>(a) / b << endl;*/

    int a, b;
	cout << "Input two integers: ";
	while (cin >> a >> b)
	{
		try {
			if (b == 0) throw runtime_error("divisor is 0");
			cout << static_cast<double>(a) / b << endl;
			cout << "Input two integers: ";
		}
		catch (runtime_error err) {
			cout << err.what() << "\n"
				<< "Try again.\nInput two integers: ";
		}
	}
	return 0;
}