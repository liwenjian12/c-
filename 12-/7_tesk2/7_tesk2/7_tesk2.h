#ifndef 7_TESK2
#define 7_TESK2
#include <string>

class NoDefault {
public:
	 NoDefault(int a){ } 
};

class C {
public:
	C() : X(0) { }
private:
	NoDefault X;
};

class Debug {
public:
	constexpr Debug(bool b = true) :rt(b), io(b), other(b) { }
	constexpr Debug(bool r, bool i, bool o) : rt(r), io(i), other(0{}
	constexpr bool any() { return rt || io || other; }

	void set_rt(bool b) { rt = b; }
	void set_io(bool b) { io = b; }
	void set_other(bool b) { other = b; }

private:
	bool rt;
	bool io;
	bool other;
};

class Account {
public:
	void calculcate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double newRate) { interestRate = newRate; }

private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate = 42.42;
	static double iniTate() { return todayRate; }
};

double Account::interestRate = initRate();

#endif // !7_TESK2

