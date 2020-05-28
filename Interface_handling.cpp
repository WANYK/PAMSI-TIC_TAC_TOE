#include "Interface_handling.h"
using namespace std;

int enter_size()
{
	int size;
	cout << "Podaj rozmiar tablicy: ";
	cin >> size;

	if (size < min_size_board)
	{
		cout << "Podany rozmiar jest za ma³y! Minimalna wielkoœæ to 3 \n";
		size = enter_size();
	}
	return size;
}

void move_statement(int circular)
{
	if (circular % 2 == 1) {
		cout << "----------------\n";
		cout << "Ruch gracza X \n";
		cout << "----------------\n";
	}
	else {
		cout << "----------------\n";
		cout << "Ruch gracza O \n";
		cout << "----------------\n";
	}
}

int enter_scope()
{
	int scope;
	cout << "Podaj zakres: ";
	cin >> scope;

	if (scope < min_scope)
	{
		cout << "Podany zakres jest za ma³y! Minimalna to 3 \n";
		scope = enter_scope();
	}
	return scope;
}

void statement(board* p_brd, int circular)
{
	if (p_brd->check_who_win() == 10 or p_brd->check_who_win() == -10)
	{
		if (circular % 2 == 1)
		{
			cout << "-------------\n";
			cout << "Zawodnik 1 wygrywa! \n";
			cout << "-------------";
		}

		else
		{
			cout << "-------------\n";
			cout << "Zawodnik 2 wygrywa! \n";
			cout << "-------------";
		}
	}
	else cout << "remis!";
}

int menu()
{
	int selection;
	cout << "--------------------------\n";
	cout << "        OX     \n";
	cout << "--------------------------\n";
	cout << "1. gracz vs gracz \n";
	cout << "2. gracz vs komputer \n";
	cout << "> ";
	cin >> selection;

	if (selection == 1 or selection == 2) return selection;
	else
	{
		cout << "Niepoprawna opcja! Sprobuj ponownie \n";
		selection = menu();
	}
}