#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void elimDups(vector<string> &words);

//cout a container like vector
template<typename sequence>
inline std::ostream& display(sequence const& seq)
{
	for (auto const& elem : seq)
		cout << elem << " " ;
	cout << endl;
	return cout;
}
string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr = 1) ? word + ending : word;
}
void biggies(vector<string> &words,
	vector<string>::size_type sz)
{
	elimDups(words);
	stable_sort(words.begin(),words.end(),[](const string &a,const string &b)
	{return a.size() < b.size();});
	auto wc = find_if(words.begin(), words.end(), [sz](const string &a)
	                                             {return a.size() >= sz; });
	auto count = words.end() - wc;
	cout << count << " " << make_plural(count, "word", "s")
		<< " of length " << sz << " or longer" << endl;

	for_each(wc, words.end(), [](const string &s) {cout << s << " "; });
	cout << endl;
}

int main()
{
	vector<string> words { "the","quick","red","fox","jump", "over","the","slow","red","turtle" };
	
	display(words);
	biggies(words,4);
	
	return 0;
}
void elimDups(vector<string> &words)
{
	
	sort(words.begin(), words.end());
	display(words);
	auto end_unique = unique(words.begin(), words.end());
	display(words);
	words.erase(end_unique, words.end());
	display(words);

}