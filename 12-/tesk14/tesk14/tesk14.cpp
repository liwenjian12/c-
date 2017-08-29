#include"tesk14.h"
int main()
{
	/*Sales_data cp5;
	std::cin >> cp5;
	std::cout << cp5 << std::endl;*/

	/*GetInput getInput;
	std::vector<std::string> vec;
	for (std::string tmp; !(tmp = getInput()).empty(); ) vec.push_back (tmp);
	for (const auto &str : vec)std::cout << str << " ";
	std::cout << std::endl;*/

	/*std::vector<int> vec = { 3, 2, 1, 4, 3, 7, 8, 6 };
	std::replace_if(vec.begin(), vec.end(), IsEqual(3), 5);
	for (int i : vec) std::cout << i << " ";
	std::cout << std::endl;*/

	std::size_t lower = 1;
	auto uppers = { 3u,4u,5u,6u,7u,8u,9u,10u,11u,12u,13u,14u };
	std::vector<IsInRange> predicates;
	for (auto upper : uppers)
		predicates.push_back(IsInRange{ lower,upper });

	std::map<std::size_t, std::size_t>count_table;
	for (auto upper : uppers)
		count_table[upper] = 0;

	std::ifstream fin("E:/2015ÈÎÎñ/C++ Primer/CppPrimer-master/data/storyDataFile.txt");
	for (std::string word; fin >> word;/* */)
		for (auto is_size_in_range : predicates)
			if (is_size_in_range(word))
				++count_table[is_size_in_range.upper_limit()];
	
	for (auto pair : count_table)
		std::cout << "count in range[1, " << pair.first <<"] "<< pair.second << std::endl;
	return 0;
}