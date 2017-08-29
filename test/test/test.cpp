#include<iostream>
#include"Sales_item.h"
int main()
{
	////1.2½ÚÁ·Ï°
	//std::cout << "Hello, World" << std::endl;
	//std::cout << 7 + 8 << " ," << 7 * 8 << std::endl;

	//1.3½ÚÁ·Ï°
	///*  /*  £¬*/ */
	//std::cout << "/*";
	//std::cout << "*/";
	////std::cout << /*"*/" */;
	//	std::cout << /* "*/" /* "/*" */;

	/*//1.4.1½ÚÁ·Ï°
	//1.9
	int sum = 0;
	int i = 50;
	while (++i && i < 101)
		sum += i;
	std::cout << sum << std::endl;
	//1.10
	int j = 10;
	while (--j)
		std::cout << j << std::endl;
	//1.11
	int x, y;
	sum = 0;
	std::cout << "Enter two ints,first one should be bigger" << std::endl;
	std::cin >> x >> y;
	while (--x > y)
		sum += x;
	std::cout << sum << std::endl;*/
	
	//1.4.2½ÚÁ·Ï°
	//1.4.3½ÚÁ·Ï°
	/*int sum = 0,value = 0;
	while (std::cin >> value)
		sum += value;
	std::cout << sum;*/

	//1.4.4½ÚÁ·Ï°
	//1.5.1½ÚÁ·Ï°
	/*Sales_item item1, item2,item3;
	std::cin >> item1 >> item2;
	if (item1.isbn() == item2.isbn())
	{
		std::cout << item1 + item2 << std::endl;
		return 0;
	}
	else
	{
		std::cerr << "Data must refer to same ISBN" << std::endl;
		return -1;
	}*/
	
	/*Sales_item total;
	if (std::cin >> total)
	{
		Sales_item trans;
		while (std::cin >> trans)
		{
			if (total.isbn() == trans.isbn())
				total += trans;
			else
			{
				std::cout << total << std::endl;
				total = trans;
			}
			std::cout << total.isbn() << std::endl;
		}
		std::cout << total.isbn() << std::endl;
	}
	else {
		std::cerr << "No data?" << std::endl;
		return -1;
	}*/


	return 0 ;
}