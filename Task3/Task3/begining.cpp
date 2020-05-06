#include <iostream>
#include "Robber.h"
#include "Helper.h"


void begining(int &lifes, robbers Robber[])
{
	std::cout << "«агрузите 5 персон (только имена, ценности будут подгружены автоматически)\n" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> Robber[i].name;
		Robber[i].life = 1;
		Robber[i].horses = rand() % 20;
		Robber[i].sabers = rand() % 10;
		Robber[i].rubies = rand() % 50;
		Robber[i].necklaces = rand() % 100;
		Robber[i].wifes = rand() % 5;
		Robber[i].money = rand() % 2000;
		Robber[i].wealth = CountWealth(Robber[i]);
		lifes++;
	}
	std::cout << "5 персон загружены" << std::endl;
}
