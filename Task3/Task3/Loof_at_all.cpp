#include "Robber.h"
#include <iostream>
#include <iomanip>
#include "Helper.h"

void look_at_all(robbers Robber[], int& lifes)
{
	int life_robbers = 0;
	for (int i = 0; i < lifes; i++)
	{
		PrintRobber(Robber[i]);
		
		if (Robber[i].life == 1)
			life_robbers++;
	}
	
	int horses = 0, sabers = 0, necklaces = 0, rubies = 0, wifes = 0, money = 0,  swealth = 0;
	for (int i = 0; i < lifes; i++)
	{
		horses += Robber[i].horses;
		sabers += Robber[i].sabers;
		rubies += Robber[i].rubies;
		necklaces += Robber[i].necklaces;
		wifes += Robber[i].wifes;
		money += Robber[i].money;
		swealth += Robber[i].wealth;
	}
	
	PrintTotal(horses, sabers, rubies, necklaces, wifes, money, swealth);
	
	std::cout << "Всего в банде (с умершими): " << lifes << std::endl;
	std::cout << "Всего живых: " << life_robbers << std::endl;
	std::cout << "Вы посмотрели всех" << std::endl << std::endl;
}
