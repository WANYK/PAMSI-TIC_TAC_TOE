#include "player.h"
using namespace std;

//Funkcja rekurencyjna, ktora pobiera od gracza ruch.
//Wychwytuje wyjscie poza granice planszy oraz miejsce w
//ktorym stoi ju¿ jakis inny znak.
turn enter_turn(board* p_brd)
{
	turn p_turn;
	cin >> p_turn;

	if (p_turn.verse < p_brd->b_size and p_turn.column < p_brd->b_size)
	{
		if (p_brd->b_pointer[p_turn.verse][p_turn.column] != ' ')
		{
			cout << "Ruch sie wydarzyl, sprobuj ponownie! \n";
			p_turn = enter_turn(p_brd);
		}
	}
	else
	{
		cout << "Wykroczyles poza zakres, sprobuj ponownie! \n";
		p_turn = enter_turn(p_brd);
	}

	return p_turn;
}


//Funkcja ktora umieszcza na planszy znak gracza
void put(board* p_board, int circular)
{
	turn p_turn = enter_turn(p_board);
	if (circular % 2 == 1)	p_board->b_pointer[p_turn.verse][p_turn.column] = player;
	else if (circular % 2 == 0)	p_board->b_pointer[p_turn.verse][p_turn.column] = enemy;
}

//Funkcja ktora jest uzywana w funkcji Dirver()
void put(board* p_brd)
{
	p_brd->b_pointer[1][1] = player;
}
