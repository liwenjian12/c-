#include <iostream>
int main()
{
	int currval = 0,val = 0;
	if (std::cin >> currval)
		{
			int ant = 1 ;
			while ( std::cin >> val)
				{
					if ( currval == val)
					++ant;
					else
						{
							std::cout << currval << " occurs " << ant << " times." << std::endl;
							currval = val;
							ant = 1;
					    }
			}
			std :: cout << currval << " occurs " << ant << " times. " << std::endl;
	}
	return 0;
}

	
