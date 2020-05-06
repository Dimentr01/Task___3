#include <string>
#include "Robber.h"
#include <iostream>
#include "Equal.h"

void Kill(std::string name, int &lifes, robbers Robber[])
{
	bool could_kill = false;
	for (int i = 0; i < lifes; i++)
		if ((Equal(name, Robber[i].name) == 1) and ((Robber[i].life) == 1))
		{
			Robber[i].life = 0;
			could_kill = true;
			break;
		}
	if (could_kill)
		std::cout << "Вы убили " << name << std::endl << std::endl;
	else
		std::cout << "Не смогли убить " << name << std::endl << std::endl;
}
