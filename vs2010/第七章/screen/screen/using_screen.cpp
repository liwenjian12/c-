#include <iostream>
#include "Srceen.h"

int main()
{
	//cout << " " << endl;
	Screen myscreen;
	char ch = myscreen.get();
	ch = myscreen.get(0,0);
}