#include <iostream>

using namespace std;
class ����
{
	//��Ա���ܶ������
public:
	int X;
};

class С�� : public ����
{
	//�µĳ�Ա
public:
	int Y;
};
class Base1
{
public:
	Base1(int i)
	{
		b1 = i;
		cout << "Base1�Ĺ��캯��������" << endl;
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
		cout << "Base2�Ĺ��캯��������" << endl;
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
		cout << " Base3ȱʡ�Ĺ��캯�������á�" << endl;
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
		cout << " Member �Ĺ��캯�������á�" << endl;
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
	Member mem;  //�����Ա
};
Derived::Derived(int i, int j, int k, int l):Base1(i),Base2(j),mem(k)
{
	d = l;
	cout << "Derived�Ĺ��캯�������á�" << endl;
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
	С�� a;//a��һ��С�ӣ�����С�Ӷ����ȴ���/�������ӣ�
	a.X = 1;
	a.Y = 2;

	Derived obj(1, 2, 3, 4);
	obj.Print();
		return 0;
}