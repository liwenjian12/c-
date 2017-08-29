

template<typename Sequence>
inline std::ostream& println(Sequence const& seq) 
{
	for (auto const& elem : seq)
		std::cout << elem << " ";
	std::cout << std::endl;
	return std::cout ;

}

inline bool
is_shorter(std::string const& lhs, std::string const& rhs)
{
	return lhs.size() < rhs.size();
}
auto eliminate_duplicates(std::vector<std::string> &vs) ->std::vector <std::string>&
{
	std::sort(vs.begin(), vs.end());
	println(vs);

	auto new_end = std::unique(vs.begin(), vs.end());
	println(vs);

	vs.erase(new_end, vs.end());
	return vs;
}

