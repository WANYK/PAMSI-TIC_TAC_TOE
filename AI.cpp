#include "AI.h"

//Funkcja ktora umieszcza znak w zadanym
//miejscu na naszej planszy
void c_put(board* p_board)
{
	turn c_move;
	c_move = best_move(p_board);
	p_board->b_pointer[c_move.verse][c_move.column] = enemy;
}

//Algorytm minimax umozliwia znalezienie najlepszego
//mozliwego ruchu przy zadanej g³êbokoœci i uzywajac
//obciecia alfa-beta.
int minimax(board* p_b, int depth, bool is_maximizing, int alfa, int beta)
{
	int effect = p_b->check_who_win();
	if (effect == 10)
	{
		return effect;
	}

	if (effect == -10)
	{
		return effect;
	}

	if (p_b->is_movie_left() == false or depth == 0)
	{
		return 0;
	}

	if (is_maximizing)
	{
		int best = n_inf;
		for (int i = 0; i < p_b->b_size; i++)
		{
			for (int j = 0; j < p_b->b_size; j++)
			{
				if (p_b->b_pointer[i][j] == ' ')
				{
					p_b->b_pointer[i][j] = player;
					int score = minimax(p_b, depth - 1, !is_maximizing, alfa, beta);
					p_b->b_pointer[i][j] = ' ';
					best = std::max(score, best);
					alfa = std::max(alfa, score);
					if (beta <= alfa) break;
				}
			}
		}
		return best;
	}

	else
	{
		int best = inf;
		for (int i = 0; i < p_b->b_size; i++)
		{
			for (int j = 0; j < p_b->b_size; j++)
			{
				if (p_b->b_pointer[i][j] == ' ')
				{
					p_b->b_pointer[i][j] = enemy;
					int score = minimax(p_b, depth - 1, !is_maximizing, alfa, beta);
					p_b->b_pointer[i][j] = ' ';
					best = std::min(score, best);
					alfa = std::min(alfa, score);
					if (beta <= alfa) break;
				}
			}
		}
		return best;
	}
}


//Funkcja ktora szuka najlepszy ruchu w danym
//momencie rozgrywki
turn best_move(board* p_b)
{
	int best_val = inf;
	turn best;
	best.verse = -1;
	best.column = -1;
	int depth = depth_2(p_b);

	for (int i = 0; i < p_b->b_size; i++)
	{
		for (int j = 0; j < p_b->b_size; j++)
		{
			if (p_b->b_pointer[i][j] == ' ')
			{
				p_b->b_pointer[i][j] = enemy;
				int move = minimax(p_b, depth, true, n_inf, inf);
				p_b->b_pointer[i][j] = ' ';

				if (move < best_val)
				{
					best_val = move;
					best.verse = i;
					best.column = j;
				}
			}
		}
	}
	return best;
}


//Funkcja ktora zawiera glebokosc szukania dla ró¿nego rozmiaru planszy
int depth_2(board* p_brd)
{
	int size = p_brd->b_size;
	if (size == 3) return 9;
	else if (size >= 4 and size < 7) return (9 - size + 1);
	else if (size >= 7 and size < 10) return 3;
	else return 2;
}