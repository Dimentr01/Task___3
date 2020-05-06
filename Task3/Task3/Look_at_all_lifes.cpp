#include <iostream>
#include <iomanip>
#include "Robber.h"
#include "Helper.h"


void Look_at_all_lifes(robbers Robber[], int& lifes)
{
	int life_robbers = 0;
	for (int i = 0; i < lifes; i++)
	{
		if (Robber[i].life == 0)
			continue;
		
		life_robbers++;
		PrintRobber(Robber[i]);
	}
		
	int horses = 0, sabers = 0, necklaces = 0, rubies = 0, wifes = 0, money = 0, swealth = 0;
	
	for (int i = 0; i < lifes; i++)
	{
		if (Robber[i].life == 0)
			continue;
		
		horses +=Robber[i].horses;
		sabers += Robber[i].sabers;
		rubies += Robber[i].rubies;
		necklaces += Robber[i].necklaces;
		wifes += Robber[i].wifes;
		money += Robber[i].money;
		swealth += Robber[i].wealth;
	}

	PrintTotal(horses, sabers, rubies, necklaces, wifes, money, swealth);
	
	std::cout << "Всего живых: " << life_robbers << std::endl;
	std::cout << "Вы посмотрели всех живых" << std::endl << std::endl;
}
