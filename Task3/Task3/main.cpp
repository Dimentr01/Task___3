#include <iostream>
#include <ctime>
#include "Robber.h"
#include "Begining.h"
#include "menu.h"
#include "Helper.h"

int lifes = 0;
robbers Robber[Robbers];

int main(int argc, char* argv[])
{
	std::srand(unsigned(std::time(0)));
	std::system("chcp 1251");
	begining(lifes, Robber);
	menu(lifes, Robber);
}
