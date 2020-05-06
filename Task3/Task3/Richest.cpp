#include <iostream>
#include "Robber.h"
#include "Helper.h"

void Richest(robbers Robber[], int &lifes)
{
	int k = 0;
	int richest = Robber[0].wealth;
	for (int i = 0; i < lifes; i++)
		if ((Robber[i].wealth > richest) and (Robber[i].life == 1))
		{
			richest = Robber[i].wealth;
			k = i;
		}
			
	PrintRobber(Robber[k]);
	
	std::cout << "Богач найден" << std::endl << std::endl;
}
