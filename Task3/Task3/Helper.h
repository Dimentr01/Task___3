#pragma once
#include <string>
#include "Robber.h"

const int Robbers = 40;

const int ident_life = 5;
const int ident = 7;

void PrintRobber(const robbers& robber);

void PrintTotal(const int& horses, const int& rubies, const int& necklaces, const int& sabers, const int& wifes, const int& money, const int& swealth);

int CountWealth(const robbers& robber);

// Для графиков
std::wstring string_to_wstring(std::string str);