#include <string>
#include <iostream>
#include "Equal.h"
#include "Kill.h"
#include "Look_at_all.h"
#include "Look_at_all_lifes.h"
#include "Find.h"
#include "draw.h"
#include "Richest.h"
#include "Add.h"

void menu(int &lifes, robbers Robber[])
{
	std::string a, k, r, f, l, e;
	std::string v;
	std::string name;
	std::cout << "Вы в главном меню" << std::endl;
	std::cout << "Выберите действие" << std::endl;
	std::cout << "If you want to KILL-enter 1" << std::endl;
	std::cout << "If you want to ADD-enter 2" << std::endl;
	std::cout << "If you want to find RICHEST-enter 3" << std::endl;
	std::cout << "If you want to FIND somebody-enter 4" << std::endl;
	std::cout << "If you want to LOOK AT ALL ALIVE-enter 5" << std::endl;
	std::cout << "If you want to LOOK AT ALL-enter 6" << std::endl;
	std::cout << "If you want to SEE DIAGRAMS-enter 7" << std::endl;
	std::cout << "If you want to EXIT-write Exit" << std::endl;
	while (true)
	{
		std::cin >> v;
		if (Equal(v, "1") == 1)
		{
			std::cout << "Enter the name, who kills" << std::endl;
			std::cin >> name;
			Kill(name, lifes, Robber);
		}
		if (Equal("2", v) == 1)
			Add(lifes, Robber);
		if (Equal(v, "3") == 1)
			Richest(Robber, lifes);
		if (Equal(v, "4") == 1)
			Find(Robber, lifes);
		if (Equal(v, "5") == 1)
			Look_at_all_lifes(Robber, lifes);
		if (Equal(v, "6") == 1)
			look_at_all(Robber, lifes);
		if (Equal(v, "7") == 1)
			draw2(Robber, lifes);
		if (Equal(v, "Exit") == 1)
			break;
		
		std::cout << "Выберите действие" << std::endl;
		std::cout << "If you want to KILL-enter 1" << std::endl;
		std::cout << "If you want to ADD-enter 2" << std::endl;
		std::cout << "If you want to find RICHEST-enter 3" << std::endl;
		std::cout << "If you want to FIND somebody-enter 4" << std::endl;
		std::cout << "If you want to LOOK AT ALL ALIVE-enter 5" << std::endl;
		std::cout << "If you want to LOOK AT ALL-enter 6" << std::endl;
		std::cout << "If you want to SEE DIAGRAMS-enter 7" << std::endl;
		std::cout << "If you want to EXIT-write Exit" << std::endl;
	}
}
