#include <windows.h>
#include <iostream>
#include <iomanip>
#include <string>
#include "Robber.h"
#include "Helper.h"


void PrintRobber(const robbers& robber)
{
	std::cout << robber.name << std::endl;
	std::cout << std::setw(ident_life) << (robber.life > 0 ? "Жив" : "Мертв");
	std::cout << std::setw(ident) << robber.horses;
	std::cout << std::setw(ident) << robber.sabers;
	std::cout << std::setw(ident) << robber.rubies;
	std::cout << std::setw(ident) << robber.necklaces;
	std::cout << std::setw(ident) << robber.wifes;
	std::cout << std::setw(ident) << robber.money;
	std::cout << "   Богатство: ";
	std::cout << std::setw(ident_life / 2 + ident) << robber.wealth;
	std::cout << std::endl << std::endl;
}

void PrintTotal(const int& horses, const int& rubies, const int& necklaces, const int& sabers, const int& wifes, const int& money, const int& swealth)
{
	std::cout << "Итого" << std::endl;
	std::cout << std::setw(ident_life + ident) << horses;
	std::cout << std::setw(ident) << rubies;
	std::cout << std::setw(ident) << necklaces;
	std::cout << std::setw(ident) << sabers;
	std::cout << std::setw(ident) << wifes;
	std::cout << std::setw(ident) << money;
	std::cout << "   Богатство: ";
	std::cout << std::setw(ident_life / 2 + ident) << swealth << std::endl;
}

int CountWealth(const robbers& robber)
{
	return 500 * robber.horses + 
		100 * robber.sabers + 
		50 * robber.rubies + 
		10 * robber.necklaces +
		robber.money -
		200 * robber.wifes ;
}

std::wstring string_to_wstring(std::string str) {
	// узнаем размер буфера
	int requiredSize = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, 0, 0);
	
	if (requiredSize > 0) {
		// создаем буфер
		wchar_t* buffer = new wchar_t[requiredSize];
		// копируем в буфер
		MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &buffer[0], requiredSize);

		// перемещаем в строку
		std::wstring convertedString(buffer);
		delete[] buffer;
		
		return convertedString;
	}

	std::wstring empty;
	return empty;
}