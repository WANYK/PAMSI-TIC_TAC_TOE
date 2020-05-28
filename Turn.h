#pragma once
#include <iostream>
#define player 'X'
#define enemy 'O'

struct turn
{
	int verse;
	int column;
};

std::istream& operator >> (std::istream& stream, turn& move);
std::ostream& operator << (std::ostream& stream, turn& move);