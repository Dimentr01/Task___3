#include <iostream>
#include "Add.h"
#include "Helper.h"

void Add(int &lifes, robbers Robber[])
{
	if (lifes == Robbers)
	{
		std::cout << "You can't add more robbers! You have " << lifes << " robbers!" << std::endl << std::endl;
		return;
	}
		
	std::cout << "Enter the name" << std::endl;
	std::cin >> Robber[lifes].name;
	
	std::cout << "Enter the number of horses" << std::endl;
	std::cin >> Robber[lifes].horses;
	
	std::cout << "Enter the number of sabers" << std::endl;
	std::cin >> Robber[lifes].sabers;
	
	std::cout << "Enter the number of rubies" << std::endl;
	std::cin >> Robber[lifes].rubies;
	
	std::cout << "Enter the number of necklaces" << std::endl;
	std::cin >> Robber[lifes].necklaces;
	
	std::cout << "Enter the number of wifes" << std::endl;
	std::cin >> Robber[lifes].wifes;
	
	std::cout << "Enter the number of money" << std::endl;
	std::cin >> Robber[lifes].money;
	
	Robber[lifes].wealth = CountWealth(Robber[lifes]);
	Robber[lifes].life = 1; // new robber is life robber

	lifes++;
	
	std::cout << "You added him" << std::endl;
}
