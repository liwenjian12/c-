#include <iostream>
#include <string>
#ifndef SCREEN_H_
#define SCREEN_H_
using namespace std;
using std::string;
class Screen
{
public:
	void some_member()const;
	typedef std::string::size_type pos;
	Screen() ;
	Screen(pos ht,pos wd,char c):height(ht),width(wd),contents(ht * wd,c£©{ }
	char get() const
	{ return contents[cursor];}
    inline char get(pos ht,pos wd) const;
	inline Screen &move(pos r,pos c);
	
private:
	mutable size_t access_ctr;
	pos cursor = 0 ;
	pos height = 0,width = 0;
	std::string contents;
public:
	Screen &set(char);
	Screen &set(pos,pos,char);
};






class Window_mgr
{
private:
	std::vector<Screen> screens{Screen(24,80,' ')};
};
#endif