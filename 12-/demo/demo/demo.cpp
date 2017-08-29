#include <iostream>

using namespace std;
class 老子
{
	//成员：很多像代码
public:
	int X;
};

class 小子 : public 老子
{
	//新的成员
public:
	int Y;
};
class Base1
{
public:
	Base1(int i)
	{
		b1 = i;
		cout << "Base1的构造函数被调用" << endl;
	}
	void Print() const
	{
		cout << b1 << endl;
	}
private:
	int b1;
};

class Base2
{
private:
	int b2;
public:
	Base2(int i)
	{
		b2 = i;
		cout << "Base2的构造函数被调用" << endl;
	}
	void Print()
	{
		cout << b2 << endl;
	}
};

class Base3
{
private:
	int b3;
public:
	Base3()
	{
		b3 = 0;
		cout << " Base3缺省的构造函数被调用。" << endl;
	}
	void Print()
	{
		cout << b3 << endl;
	}
};

class Member
{
public:
	Member(int i)
	{
		m = i;
		cout << " Member 的构造函数被调用。" << endl;
	}
	int Member:: GetM()
	{
		return m;
	}
private:
	int m;
};
class Derived : public Base2, public Base1, public Base3
{
public:
	Derived(int i, int j, int k, int l);
	void Print();
private:
	int d;
	Member mem;  //对象成员
};
Derived::Derived(int i, int j, int k, int l):Base1(i),Base2(j),mem(k)
{
	d = l;
	cout << "Derived的构造函数被调用。" << endl;
}
void Derived::Print()
{
	Base1::Print();
	Base2::Print();
	Base3::Print();
	cout << mem.GetM() << endl;
	cout << d << endl;
}
int main()
{
	小子 a;//a是一个小子，创建小子对象，先创建/构造老子！
	a.X = 1;
	a.Y = 2;

	Derived obj(1, 2, 3, 4);
	obj.Print();
		return 0;
}