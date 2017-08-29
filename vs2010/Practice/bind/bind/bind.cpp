#include<iostream>
#include<string>
#include<map>
#include <algorithm>
#include <cctype>
using namespace std;


int main()
{
	map<string, size_t> word_count;
    string word;
	while (cin >> word)
		{
		   for (auto& ch : word)
				ch = tolower(ch);
		   word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
			++word_count[word];
		}
	for (const auto &w : word_count)
		cout << w.first << " occurs " << w.second
		<< ((w.second > 1) ? " times" : " time") << endl;

	return 0;

}
