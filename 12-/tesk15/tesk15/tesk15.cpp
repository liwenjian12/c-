#include"tesk15.h"
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<memory>
#include<functional>

using namespace std;
double print_total(ostream &os, const Quote &item, size_t n);


int main()
{
	//Quote q("textbook", 10.60);
	//Bulk_quote bq("textbook", 10.60, 10, 0.30);
	//Disc_quote d("textbook", 10.5, 10, 0.3);
	//print_total(cout, q, 12);
	//print_total(cout, bq, 12);

	/*Pub_Derv d1;
	Base *p = &d1;
	Priv_Derv d2;
	//p = &d2;
	Prot_Derv d3;
    //p = &d3;
	Derived_from_Public dd1;
	p = &dd1;
	Derived_from_Private dd2;
	//p =& dd2;
	Derived_from_Protected dd3;
	//p = &dd3;*/
	std::vector<Quote> v;
	for (unsigned i = 1; i != 10; ++i)
		v.push_back(Bulk_quote("sss", i * 10.1, 10, 0.3));

	double total = 0;
	for (const auto& b : v)
	{
		total += b.net_price(20);
	}
	std::cout << total << std::endl;
	std::cout << "=====================\n\n";

	std::vector<std::shared_ptr<Quote>>pv;
	for(unsigned i =1;i!= 10;++i)
		pv.push_back(std::make_shared<Bulk_quote>(Bulk_quote("sss", i * 10.1, 10, 0.3)));
	
	double total_p = 0;
	for (auto p : pv)
	{
		total_p += p->net_price(20);
	}
	std::cout << total_p << std::endl;

	return 0;
}

double print_total(ostream &os, const Quote &item, size_t n)
{
	double ret = item.net_price(n);
	os << "ISBN:" << item.isbn()
		<< "# sold: " << n << " total due: " << ret << std::endl;

	return ret;
}