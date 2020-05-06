#include <string>
#include <iostream>
#include "Equal.h"
#include "Helper.h"

void Find(robbers Robber[], int& lifes)
{
	int p = 0;
	std::string a;
	std::cout << "Enter the name" << std::endl;
	std::cin >> a;
	std::cout << std::endl;
	for (int i = 0; i < lifes; i++)
	{
		if (Equal(a, Robber[i].name) == 1)
		{
			PrintRobber(Robber[i]);
			p++;
		}
	}
		
	if (p > 1)
		std::cout << "Вы нашли их" << std::endl << std::endl;
	else if (p == 1)
		std::cout << "Вы нашли его" << std::endl << std::endl;
	else
		std::cout << "Вы не нашли его" << std::endl << std::endl;
}
