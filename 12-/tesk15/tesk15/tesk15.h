#ifndef TESK15_H
#define TESK15_H
#include<string>
#include<iostream>



class Quote {
	friend bool operator !=(const Quote& lhs, const Quote& rhs);
public:
	Quote() {std::cout << "default constructing Quote\n";}
	Quote(const std::string &s, double p) :bookNo(s), price(p)
	{
		std::cout << "Quote:construntor taking 2 parameters\n";
	}
	// copy constructor
	Quote(const Quote& q) :bookNo(q.bookNo), price(q.price)
	{
		std::cout << "Quote:copy constructing\n";
	}
	// move constructor
	Quote(Quote&& q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price))
	{
		std::cout << "Quote:move constructing\n";
	}
	Quote& operator =(const Quote& rhs)
	{
		if (*this != rhs)
		{
			bookNo = rhs.bookNo;
			price = rhs.price;
		}
		std::cout << "Quote:copy = () \n";
		return *this;
	}

	//! clone self
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && {return new Quote(std::move(*this)); }

	std::string isbn() const { return bookNo; }
	virtual double net_price(std::size_t n) const { return n *price; }
	virtual ~Quote() {
		std::cout << "destructing Quote\n";
	}
	virtual void debug() const;

	
protected:
	std::string bookNo;
	double price = 10.0;

};

bool inline
operator !=(const Quote& lhs, const Quote& rhs)
{
	return (lhs.bookNo != rhs.bookNo)
		&&
		(lhs.price != rhs.price);
}
void Quote::debug()const
{
	std::cout << "data members of this class:\n"
		<< "bookNo= " << this->bookNo << " "
		<< "price= " << this->price << " ";

}

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string& b, double p, std::size_t q, double d) :
		Quote(b, p), quantity(q), discount(d) {}

	virtual double net_price(std::size_t n)const override = 0;
protected:
	std::size_t quantity = 0;
	double      discount = 0.0;
};

class Bulk_quote :public Disc_quote 
{
public:
	Bulk_quote() { std::cout << "default constructing Bulk_quote\n"; }
	
	using Disc_quote::Disc_quote;
	
	//copy constructor
	Bulk_quote(const Bulk_quote &bq) :Disc_quote(bq)
	{
		std::cout << "Bulk_quote:constructor taking 4 parameters\n";
	}
	//move constructor
	Bulk_quote(Bulk_quote&& bq) : Disc_quote (std::move(bq)) 
	{
		std::cout << "Bulk_quote:move constructor\n";
	}
	//copy =()
	Bulk_quote& operator = (const Bulk_quote& rhs)
	{
		Disc_quote::operator=(rhs);
		std::cout << "Bulk_quote:copy=()\n";

		return *this;
	}
	// move =()

	Bulk_quote& operator =(Bulk_quote&& rhs) noexcept
	{
		Disc_quote::operator =(std::move(rhs));
		std::cout << "Bulk_quote : move =()\n";

		return *this;
	}


	double net_price(std::size_t n) const override;
	void debug() const override;

	~Bulk_quote() override
	{
		std::cout << "destructing Bulk_quote\n";
	}

private:
	
};
void Bulk_quote::debug()const
{
	std::cout << "data members of this class:\n"
		<< "bookNo= " << this->bookNo << " "
		<< "price= " << this->price << " ";

}

double Bulk_quote::net_price(size_t cnt) const
{
	if (cnt >= quantity)
		return cnt * (1 - discount)*price;
	else
		return cnt *price;
}

class Limit_quote:public Disc_quote {
public:
	Limit_quote() = default;
	Limit_quote(const std::string &s, double p, std::size_t max, double disc) :
		Disc_quote(s, p,max, disc) {}

	double net_price(std::size_t n) const override
	{
		return n * price *(n < quantity ? 1 - discount : 1);
	}
private:
	std::size_t max_qty = 0;
	double  discount = 0.0;
};

//double Limit_quote::net_price(std::size_t n) const
//{
//	if (n > max_qty)
//		return max_qty * price * discount + (n - max_qty) * price;
//	else
//		return n * discount * price;
//}


/*--------------------------class Base------------------------*/
class Base {
public:
	void pub_mem();
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_Derv :public Base
{
	void memfcn(Base &b) { b = *this; }
};
struct Priv_Derv :private Base
{
	void memfcn(Base &b) { b = *this; }
};
struct Prot_Derv :protected Base
{
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Public :public Pub_Derv
{
	void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Private :public Priv_Derv
{
	//void memfcn(Base &b) { b = *this; }
};
struct Derived_from_Protected :public Prot_Derv
{
	void memfcn(Base &b) { b = *this; }
};
#endif // !TESK15_H

