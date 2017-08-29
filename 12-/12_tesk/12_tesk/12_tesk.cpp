#include"12_tesk.h"
//#include<iostream>
#include<memory>
#include<fstream>
#include<cstring>
#include<algorithm>
#include<iterator>

using namespace std;

 shared_ptr <vector<int>>  alloc_vector() {
	return make_shared <vector <int>>();
}
void assign_vector(shared_ptr<vector<int>> p) {
	int a;
	while (cin >> a)p->push_back(a);
}
void print_vector(shared_ptr<vector<int>> p) {
	for (auto a : *p) cout << a << " ";
	cout << endl;
}

void input_reverse_output_string(int n)
{
	allocator<string>alloc;
	auto  const p = alloc.allocate(n);
	string s;
	auto q = p;
	while (cin >> s &&q != p + n)
		alloc.construct(q++, s);
	while (q != p)
	{
		cout << *--q << " ";
		alloc.destroy(q);
	}
	alloc.deallocate(p, n);
}
void runQueries(ifstream& infile)
{
	TextQuery tq(infile);
	while (true)
	{
		cout << "enter word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		print(cout, tq.query(s)) << endl;
	}
}
int main()
{
	/*const StrBlob csb{ "hello","world","pezy" };
	StrBlob sb{ "hello","world","Mooophy" };

	cout << csb.front() << " " << csb.back() << endl;
	sb.back() = "pezy";
	cout << sb.front() << " " << sb.back() << endl;*/
	/*shared_ptr<vector<int>> ptr = alloc_vector();
	assign_vector(ptr);
	print_vector(ptr);*/

	//destination dest("220.181.111.111", 10086);
	//f(dest);
	//unique_ptr<string>p1(new string("hello"));
	//auto p2 = p1;
	//cout << *p1 << endl;
	//p1.reset(nullptr);
	//17题写在书上

	/*ifstream ifs("book.txt");
	StrBlob sb;
	string s;
	while (getline(ifs, s))
	{
		sb.push_back(s);
	}
	for (StrBlobPtr sbp = sb.begin(); sbp != sb.end(); sbp.incr())
	{
		cout << sbp.deref() << endl;
	}*/

	/*const char *c1 = "hello";
	const char *c2 = "world";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	cout << r << endl;

	string s1 = "hello";
	string s2 = "world";
	strcpy_s(r, len, (s1 + s2).c_str());
	cout << r << endl;

	delete[] r;*/

	/*cout << "how long do you want the string";
	int size{ 0 };
	cin >> size;
	char *input = new char[size + 1]();
	cin.ignore();
	cout << "input the string: ";
	cin.get(input, size + 1);
	cout << input;
	delete[] input;*/

	input_reverse_output_string(5);
	ifstream ifs("book.txt");
	runQueries(ifs);
	/*ifstream file("E:/2015任务/C++ Primer/CppPrimer-master/data/storyDataFile.txt");
	vector<string>input;
	map<string, set<decltype(input.size())>> dictionary;
	decltype(input.size()) lineNo{ 0 };

	for (string line; getline(file, line); ++lineNo)
	{
		input.push_back(line);
		istringstream line_stream(line);
		for (string text, word; line_stream >> text; word.clear())
		{
			remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
			dictionary[word].insert(lineNo);
		}
	}

	while (true)
	{
		cout << "enter word to look for,or q to quit: ";
		string s;
		if (!(cin >> s) || s == "q")break;
		auto found = dictionary.find(s);
		if (found != dictionary.end())
		{
			cout << s << "occurs" << found->second.size() << (found->second.size() > 1 ? "times" : "time") << endl;
			for (auto i : found->second)
				cout << "\t(line" << i + 1 << ") " << input.at(i) << endl;
		}
		else cout << s << " occurs 0 time" << endl;
	}*/
	return 0;
}