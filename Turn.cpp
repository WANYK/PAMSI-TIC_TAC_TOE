#include "Turn.h"
#include <iostream>
using namespace std;

istream& operator >> (istream& stream, turn& move)
{
	cout << "Wybierz wers: ";
	stream >> move.verse;
	if (!stream)
	{
		stream.setstate(ios::failbit);
		return stream;
	}

	cout << "Wybierz kolumne: ";
	stream >> move.column;
	if (!stream)
	{
		stream.setstate(ios::failbit);
		return stream;
	}

	return stream;
}

ostream& operator << (ostream& stream, turn& move)
{
	stream << "wers: " << move.verse << " \n kolumna: " << move.column << "\n";
	return stream;
}