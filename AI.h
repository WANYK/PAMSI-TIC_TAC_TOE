#pragma once
#include <algorithm>
#include "Turn.h"
#include "Board.h"
#define inf 10000000
#define n_inf -10000000

int minimax(board* p_b, int depth, bool is_maximizing, int alfa, int beta);
turn best_move(board* p_b);
void c_put(board* p_board);
int depth_2(board* p_board);