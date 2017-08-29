#ifndef TESK14_H
#define TESK14_H
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<algorithm>

class Sales_data {
	friend std::istream& operator >> (std::istream&, Sales_data&); // input
	friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
	friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition

public:
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(n*p) {}
	Sales_data() : Sales_data("", 0, 0.0f) {}
	Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f) {}
	Sales_data(std::istream &is);

	Sales_data& operator+=(const Sales_data&); // compound-assignment
	std::string isbn() const { return bookNo; }

private:
	inline double avg_price() const;

	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

std::istream& operator >> (std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
	return units_sold ? revenue / units_sold : 0;
}




/*----------------------------class getinput-----------------*/
class GetInput {
public:
	GetInput(std::istream &i = std::cin) :is(i) {}
	std::string operator()()const {
		std::string str;
		std::getline(is, str);
		return is ? str : "li"/*std::string()*/;
	}
private:
	std::istream &is;
};

class IsEqual {
	int value;
public:
	IsEqual(int v) :value(v) {}
	bool operator()(int elem)
	{
		return elem == value;
	}
};


/*--------------------class IsInRange-----------------------*/
struct IsInRange {
	IsInRange(std::size_t lower, std::size_t upper) :_lower(lower), _upper(upper) {}
	bool operator()(std::string const& str) const
	{
		return str.size() >= _lower && str.size() <= _upper;
	}
	std::size_t lower_limit() const
	{
		return _lower;
	}
	std::size_t upper_limit() const
	{
		return _upper;
	}
private:
	    std::size_t _lower;
		std::size_t _upper;
};
#endif // !TESK14_H

