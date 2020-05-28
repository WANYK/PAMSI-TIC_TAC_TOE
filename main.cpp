#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>

#include "AI.h"
#include "Board.h"
#include "Interface_handling.h"
#include "Turn.h"
#include "Player.h"

using namespace std;

vector<int> T_2nd_move;
vector<int> T_1st_move;


//Funkcja ktora wychwytuje ilosc czasu potrzebnego komputerowi na obliczenie
//ruchu dla roznego rozmiaru tablicy i warunkow rozpoczecia gry.
void driver()
{
	int size[9] = { 3,4,5,6,7,8,9,10,15 };
	for (int i = 0; i < 9; i++)
	{
		board* p_brd = new board(size[i], size[i]);
		put(p_brd);
		auto start = chrono::steady_clock::now();
		c_put(p_brd);
		auto end = chrono::steady_clock::now();
		T_2nd_move.push_back((int)chrono::duration_cast<chrono::microseconds>(end - start).count());
		cout << "Wykonane \n";
		p_brd->~board();
	}

	for (int i = 0; i < 9; i++)
	{
		board* p_brd = new board(size[i], size[i]);
		auto start = chrono::steady_clock::now();
		c_put(p_brd);
		auto end = chrono::steady_clock::now();
		T_1st_move.push_back((int)chrono::duration_cast<chrono::microseconds>(end - start).count());
		cout << "wykonane \n";
		p_brd->~board();
	}

	ofstream file("effects.txt");
	file << "AI -> drugi ruch \n";
	for (int i = 0; i < 9; i++)
	{
		file << T_2nd_move[i] << "\n";
	}

	file << "AI -> pierwszy ruch \n";
	for (int i = 0; i < 9; i++)
	{
		file << T_1st_move[i] << "\n";
	}
	file.close();
}


int main()
{
	//driver();
	int circular = 1;
	bool pv_c = false;
	bool is_left = true;
	int selection = menu();
	int size = enter_size();
	int scope = enter_scope();

	if (selection == 2) pv_c = true;
	board* p_brd = new board(size, scope);
	p_brd->show();
	while (is_left)
	{
		move_statement(circular);
		if (circular % 2 == 1)
		{
			put(p_brd, circular);
			p_brd->show();
		}

		else if (circular % 2 == 0)
		{
			if (pv_c) c_put(p_brd);
			else put(p_brd, circular);
			p_brd->show();
		}

		if (p_brd->check_who_win() == 10 or p_brd->check_who_win() == -10)
		{
			break;
		}
		is_left = p_brd->is_movie_left();
		circular++;
	}
	statement(p_brd, circular);
	p_brd->~board();
}