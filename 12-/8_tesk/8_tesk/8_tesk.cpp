#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"ex7_26.h"
using namespace std;

void Readfiletovec(const string& fileName, vector<string>& v)
{
	ifstream ifs(fileName);
	if (ifs)
	{
		string buf;
		while (ifs>>buf)
			v.push_back(buf);
	}
}
istream& func(istream &is)
{
	string buf;
	while (is >> buf)
		cout << buf << endl;
	is.clear();
	return is;
}
/*istream& read(istream& is ) {
	string s;
	while(is>>s)
	   cout << s << endl;
	s.clear();
	return is;
}*/

int main(/*int argc, char **argv*/)
{
	//read(cin);
	vector<string> v;
	Readfiletovec("book.txt", v);
	for (const auto &str : v)
	{
		istringstream iss(str);
		string word;
		while (iss >> word)cout << word << endl;
	}
	/*ifstream input(argv[1]);
	Sales_data total;
	if (read(input, total))
	{
		Sales_data trans;
		while (read(input, trans))
		{
			if (total.isbn() == trans.isbn())
				total.combine(trans);
			else
			{
				print(cout, total) << endl;
				total = trans;
			}
		}
		print(cout, total) << endl;
	}
	else
	{
	    cerr << "no data?" << endl;
    }*/
	//istringstream iss("hello");
	//func(iss);
	/*ofstream fout("jar.txt");
	fout << "liwenjian" << endl;
	ifstream fin;
	fin.open("jar.txt");
	string s;
	getline(fin, s);
	cout << s << endl;*/
	return 0;
}