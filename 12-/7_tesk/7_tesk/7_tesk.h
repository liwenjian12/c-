#ifndef TESK7_
#define TESK7_
#include<string>
#include<vector>
#include<iostream>
class Sales_data {
	friend std::istream &read_Sales(std::istream &is, Sales_data &item);
	friend std::ostream &print_Sales(std::ostream &os, const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs, const Sales_data &rhs);
public:
   // Sales_data() = default;
	//Sales_data(const std::string &s) :bookNo(s) { }
	//Sales_data() :units_sold(0), revenue(0) { }
	Sales_data(const std::string &s, unsigned n, double p) 
		:bookNo(s), units_sold(n), revenue(p*n)
	{
		std::cout << "Sales_data(const std::string&,unsigned,double)" << std::endl;
	}

	Sales_data():Sales_data("",0,0.0f)
	{
		std::cout << "Sales_data()" << std::endl;
	}

	Sales_data(const std::string &s):Sales_data(s,0,0.0f)
	{
		std::cout << "Sales_data(const std::string&)" << std::endl;
	}
	Sales_data(std::istream &);

	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data &rhs);

private:
	inline double avg_price()const;
private:
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

inline
double Sales_data::avg_price()const
{
	return units_sold ? revenue / units_sold : 0;
}

Sales_data::Sales_data(std::istream &is) :Sales_data()
{
	std::cout << "Sales_data(istream &is)" << std::endl;
	read_Sales(is, *this);
}
Sales_data& Sales_data::combine(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}

std::istream &read_Sales(std::istream &is, Sales_data &item)
{
	double price = 0;
	is >> item.bookNo >> item.units_sold >> price;
	item.revenue = price*item.units_sold;
	return is;
}
//Sales_data::Sales_data(std::istream &is)
//{
//	read_Sales(is, *this);
//}
std::ostream &print_Sales(std::ostream &os, const Sales_data &item)
{
	os << item.bookNo << " " << item.units_sold << " " << item.revenue;
	std::cout << std::endl;
	return os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

class Person;
std::istream &read(std::istream &is, Person &man);
class Person {
	friend std::istream &read(std::istream &is, Person &man);
	friend std::ostream &print(std::ostream &os, const Person &man);
public:
	Person() = default;
	Person(const std::string &sname,const std::string &saddr):name(sname),addr(saddr){ }
	Person(std::istream &is) {  read(is, *this); }

    std::string Getname() const{ return name; }
	std::string Getaddr() const{ return addr; }
private:
	std::string name;
	std::string addr;
};

std::istream &read(std::istream &is,Person &man)
{
	is >> man.name >> man.addr;
	if (!is)man = Person();
	return is;
}
std::ostream &print(std::ostream &os, const Person &man)
{
	os << man.name << man.addr;
	return os;
}


class Screen;

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	inline void clear(ScreenIndex);
private:
	std::vector<Screen> screens;
};



class Screen {
	friend void Window_mgr::clear(ScreenIndex);
public:
	using pos = std::string::size_type;

	Screen() = default;
	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht*wd, c) {}

	char get()const { return contents[cursor]; }
	char get(pos r, pos c)const { return contents[r*width + c]; }
	inline Screen &move(pos r,pos c);
	inline Screen &set(char c);
	inline Screen &set(pos r, pos c, char ch);

    Screen :: pos Screen::size()const
	{
		return height *width;
	}

	const Screen &display(std::ostream &os)const { do_display(os); return *this; }
	Screen &display(std::ostream &os) { do_display(os); return *this; }
private:
	void do_display(std::ostream &os)const { os << contents; }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

};

inline void Window_mgr::clear(ScreenIndex i)
{
	if (i >= screens.size())return;
	Screen &s = screens[i];
	s.contents = std::string(s.height *s.width, ' ');
}

inline Screen& Screen::move(pos r, pos c)
{
	cursor = r*width + c;
	return *this;
}
inline Screen& Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}
inline Screen& Screen::set(pos r, pos c, char ch)
{
	contents[r*width + c] = ch;
	return *this;
}


class Y;
class X {
private:
	Y *ptr1 = nullptr;
};
class Y {
private:
	X object;
};
#endif
