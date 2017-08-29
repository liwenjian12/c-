#ifndef BASKET_H
#define BASKET_H

#include"tesk15.h"
#include<set>
#include<memory>
// a basket of objects from Quote hierachy ,using smart pointer
class Basket
{
public:
	void ass_item(const Quote& sale)
	{
		items.insert(std::shared_ptr<Quote>(sale.clone()));
	}

	double total_receipt(std::ostream& os)const;
private:
	//function to compare needed by the multiset member
	static bool compare(const std::shared_ptr<Quote>& lhs,
		const std::shared_ptr<Quote>& rhs)
	{
		return lhs->isbn() < (rhs-> isbn());
	}
	// hold multiple quotes ,ordered by the compare member
	std::multiset<std::shared_ptr<Quote>, decltype(compare)* >
		items{ compare };
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend();
		iter = items.upper_bound(*iter))
	{
		sum += print_total(os, **iter, items.count(*iter));
	}
	//the number of the same book
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
#endif
