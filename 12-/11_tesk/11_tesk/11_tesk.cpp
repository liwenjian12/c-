#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

void word_transform(ifstream&, ifstream&);
map<string, string> buildMap(ifstream&);
string transform(const string&, map<string, string>&);

int main()
{
	/*map<string, vector<pair<string, string>>>famlies_map;
	string lastName, childName, birthday;
	while ([&]() {
		cout << "last name:\n";
		cin >> lastName;
		return lastName != "@q";
	}())
	{
		while ([&]() {
			cout << "child's name:\n";
			cin >> childName;
			cout << "his birthday:\n";
			cin >> birthday;
			return childName != "@q" && birthday != "@q";
		}())
		{
			famlies_map[lastName].push_back({ childName,birthday });

		}
	}
	for (const auto &e : famlies_map)
	{
		cout << e.first << ":\m";
		for (const auto &l : e.second)
		{
			cout << l.first << " " << l.second << " ";
		}

	}*/

	//multimap<string, string>families;
	//for (string lname, cname; cin >> cname >> lname; families.emplace(lname, cname));
	//for (auto const& family : families)
	//	std::cout << family.second << " " << family.first << endl;

	/*multimap<string, string>authors{
		{ "alan", "DMA" },
		{ "pezy", "LeetCode" },
		{ "alan", "CLRS" },
		{ "wang", "FTP" },
		{ "pezy", "CP5" },
		{ "wang", "CPP-Concurrency"  } };
	map<string, multiset<string>>order_authors;
	
	for (const auto &author : authors)
		order_authors[author.first].insert(author.second);*/

	/*auto found = authors.find(author);
	auto count = authors.count(author);
	while (count)
	{
		if (found->second == work)
		{
			authors.erase(found);
			break;
		}
		++found;
		--count;
	}*/
	/*for (const auto &author : order_authors)
	{
		cout << author.first << ": " ;
		for (const auto &work : author.second)
			cout << work << " ";
		cout << endl;
	}*/

		return 0;
}