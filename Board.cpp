#include "Board.h"
using namespace std;

//Konstruktor parametryczny klasy
board::board(int size, int scope)
{
	this->c_scope = scope;
	this->b_size = size;
	this->b_pointer = new char* [this->b_size];

	for (int i = 0; i < this->b_size; i++)
	{
		this->b_pointer[i] = new char[this->b_size];
	}

	for (int i = 0; i < this->b_size; i++)
	{
		for (int j = 0; j < this->b_size; j++)
		{
			this->b_pointer[i][j] = ' ';
		}
	}
}

//Destruktor klasy
board::~board()
{
	for (int i = 0; i < this->b_size; i++)
	{
		delete[] this->b_pointer[i];
	}
}

//Metoda ktora rysuje plansze w terminalu
void board::show()
{
	for (int i = 0; i < this->b_size; i++)
	{
		for (int j = 0; j < this->b_size; j++)
		{
			cout << this->b_pointer[i][j];
			if (j != this->b_size - 1) cout << "|";
		}

		if (i != this->b_size - 1)
		{
			cout << endl;
			for (int k = 0; k < this->b_size + this->b_size - 1; k++)
			{
				if (k % 2 == 1) cout << "+";
				else if (k % 2 == 0) cout << "-";
			}
			cout << endl;
		}
	}
	cout << endl;
}

//Metoda ktora sprawdza czy zosta³ jakikolwiek ruch do wykonania
bool board::is_movie_left()
{
	int count = 0;
	for (int i = 0; i < this->b_size; i++)
	{
		for (int j = 0; j < this->b_size; j++)
		{
			if (this->b_pointer[i][j] == ' ')
			{
				count++;
			}
		}
	}
	if (count > 0) return true;
	else return false;
}


//Metoda ktora sprawdza czy ktorys z graczy umiescil
//wyrywajaca ilosc znakow w rzêdzie. 
//Zwraca 10 w przypadku zwyciestwa X
//Zwraca -10 w przypadku zwyciestwa O
//Zwraca 0 w kazdym innym przypadku
int board::check_who_win()
{
	if (this->c_scope == this->b_size)
	{
		if (this->b_pointer[0][0] != ' ')
		{
			for (int i = 1; i < this->b_size; i++)
			{
				if (this->b_pointer[0][0] != this->b_pointer[i][i])
				{
					break;
				}
				else if (i == this->b_size - 1)
				{
					if (this->b_pointer[0][0] == player) return 10;
					else if (this->b_pointer[0][0] == enemy) return -10;
				}
			}
		}

		for (int j = 0; j < this->b_size; j++)
		{
			if (this->b_pointer[0][j] != ' ')
			{
				for (int i = 0; i < this->b_size; i++)
				{
					if (this->b_pointer[0][j] != this->b_pointer[i][j])
					{
						break;
					}
					else if (i == this->b_size - 1)
					{
						if (this->b_pointer[0][j] == player) return 10;
						else if (this->b_pointer[0][j] == enemy) return -10;
					}
				}
			}
		}

		for (int i = 0; i < this->b_size; i++)
		{
			if (this->b_pointer[i][0] != ' ')
			{
				for (int j = 0; j < this->b_size; j++)
				{
					if (this->b_pointer[i][0] != this->b_pointer[i][j])
					{
						break;
					}
					else if (j == this->b_size - 1)
					{
						if (this->b_pointer[i][0] == player) return 10;
						else if (this->b_pointer[i][0] == enemy) return -10;
					}
				}
			}
		}

		if (this->b_pointer[0][this->b_size - 1] != ' ')
		{
			int j = this->b_size - 1;
			for (int i = 0; i < this->b_size; i++)
			{
				if (this->b_pointer[0][this->b_size - 1] != this->b_pointer[i][j - i])
				{
					break;
				}
				else if (i == this->b_size - 1)
				{
					if (this->b_pointer[0][this->b_size - 1] == player) return 10;
					else if (this->b_pointer[0][this->b_size - 1] == enemy) return -10;
				}
			}
		}
	}

	else
	{
		int count = this->b_size - this->c_scope;
		for (int i = 0; i <= count; i++)
		{
			for (int j = 0; j <= count; j++)
			{
				if (this->b_pointer[i][j] != ' ')
				{
					for (int k = 0; k < this->c_scope; k++)
					{
						if (this->b_pointer[i][j] != this->b_pointer[i + k][j + k]) break;

						else if (k == this->c_scope - 1)
						{
							if (this->b_pointer[i][j] == player) return 10;
							else if (this->b_pointer[i][j] == enemy) return -10;
						}
					}
				}
			}
		}

		for (int i = 0; i <= count; i++)
		{
			for (int j = 0; j < this->b_size; j++)
			{
				if (this->b_pointer[i][j] != ' ')
				{
					for (int k = 0; k < this->c_scope; k++)
					{
						if (this->b_pointer[i][j] != this->b_pointer[i + k][j]) break;

						else if (k == this->c_scope - 1)
						{
							if (this->b_pointer[i][j] == player) return 10;
							else if (this->b_pointer[i][j] == enemy) return -10;
						}
					}
				}
			}
		}

		for (int i = 0; i < this->b_size; i++)
		{
			for (int j = 0; j <= count; j++)
			{
				if (this->b_pointer[i][j] != ' ')
				{
					for (int k = 0; k < this->c_scope; k++)
					{
						if (this->b_pointer[i][j] != this->b_pointer[i][j + k]) break;

						else if (k == this->c_scope - 1)
						{
							if (this->b_pointer[i][j] == player) return 10;
							else if (this->b_pointer[i][j] == enemy) return -10;
						}
					}
				}
			}
		}

		for (int i = 0; i <= count; i++)
		{
			for (int j = this->b_size - 1; j >= count; j--)
			{
				if (this->b_pointer[i][j] != ' ')
				{
					for (int k = 0; k < this->c_scope; k++)
					{
						if (this->b_pointer[i][j] != this->b_pointer[i + k][j - k]) break;

						else if (k == this->c_scope - 1)
						{
							if (this->b_pointer[i][j] == player) return 10;
							else if (this->b_pointer[i][j] == enemy) return -10;
						}
					}
				}
			}
		}
	}

	return 0;
}