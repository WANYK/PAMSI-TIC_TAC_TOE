#pragma once
#define min_size_board 3
#define min_scope 3
#include <iostream>
#include <string>
#include "Turn.h"

class board
{
public:
	char** b_pointer;
	int b_size;
	int c_scope;

	board(int size, int scope);
	~board();

	void show();
	int check_who_win();
	bool is_movie_left();
};