#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<memory>
#include<set>
#include<map>
#include"TextQuery.h"
using namespace std;

ostream &print(ostream & os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< make_plural(qr.lines->size(), "time", "s") << endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << endl;
	return os;
}
string make_plural(size_t ctr, const string &word,
	const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}




TextQuery::TextQuery(ifstream &is) :file(new vector<string>)
{
	string text;
	while (getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}
void runQueries(ifstream &infile)
{
	//infile is a ifstream,point to the file we will deal
	TextQuery tq(infile);   //保存文件并建立查询map
							// 与用户交互：提示用户输入要查询的单词，完成查询并打印结果
	while (1)
	{
		cout << "enter word to look for ,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}

}