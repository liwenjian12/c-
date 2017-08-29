#include<iostream>
#include<string>
#include"7_tesk.h"
using namespace std;


int main()
{
	/*Sales_data total;
	if (cin >> total.bookNo >> total.units_sold >> total.revenue)
	{
		Sales_data trans;
		while (cin >> trans.bookNo >> trans.units_sold >> trans.revenue) {
			if (total.bookNo == trans.bookNo)
				total.combine(trans);
			else {
				cout << total.bookNo << " " << total.units_sold << " " << total.revenue << " " << endl;
				total = trans;
			}
		}
		cout << total.bookNo << " " << total.units_sold << " " << total.revenue << endl;
	}
	else
	{
		cerr << "no data?" << endl;
		return -1;
	}*/
	/*Sales_data item1;
	print_Sales(std::cout, item1) << std::endl;

	Sales_data item2("liwenjian");
	print_Sales(std::cout, item2) << endl;

	Sales_data item3("liwenjian", 34, 30);
	print_Sales(cout, item3) << endl;

	Sales_data item4(cin);
	print_Sales(cout, item4) << endl;*/

	/*Sales_data item5(cin);
	if (!item5.isbn().empty())
	{
		istream &is = cin;
		while (is) {
			Sales_data item6(is);
			if (item5.isbn() == item6.isbn())
				item5.combine(item6);
			else {
				print_Sales(cout, item5) << endl;
				item5 = item6;
			}
		}
	}
	else {
		cerr << "no data?" << endl;
		return -1;
	}*/
	/*Screen myScreen(5, 5, 'X');
	myScreen.move(4, 0).set('#').display(cout);
	cout << "\n";
	myScreen.display(cout);
	cout << "\n";*/
	Screen myScreen(5, 5, 'X');
	cout << "1. default way: " << endl;
	cout << "----------------" << endl;
	Sales_data s1;

	cout << "\n2. use std::string as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s2("CPP-Primer-5th");

	cout << "\n3. complete parameters: " << endl;
	cout << "----------------" << endl;
	Sales_data s3("CPP-Primer-5th", 3, 25.8);

	cout << "\n4. use istream as parameter: " << endl;
	cout << "----------------" << endl;
	Sales_data s4(std::cin);

	return 0;
}