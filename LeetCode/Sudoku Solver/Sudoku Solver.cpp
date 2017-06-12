// Sudoku Solver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
	Solution()
	{
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		memset(cell, 0, sizeof(cell));
	}

	bool isOK(int number, int i, int j, vector<vector<char>>& board)
	{
		int t = number - 1;
		if (row[i][t] || col[j][t] || cell[i / 3 * 3 + j / 3][t]) return false;
		return true;
	}

	void solveSudoku(vector<vector<char>>& board) {
		if (board.size() != 9) return;

		init(board);
		sudoku(0, 0, board);
	}

	void init(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') continue;
				int t = board[i][j] - '0' - 1;
				row[i][t] = true;
				col[j][t] = true;
				cell[i / 3 * 3 + j / 3][t] = true;
			}
		}
	}

	bool sudoku(int i, int j, vector<vector<char>>& board)
	{

		for (; i < 9; i++)
		{
			if (board[i].size() != 9) return false;
			for (j=0; j < 9; j++)
			{
				if (board[i][j] != '.') continue;

				for (int k = 1; k <= 9; k++)
				{
					if (isOK(k, i, j, board))
					{
						int t = k - 1;
						board[i][j] = k+'0';
						row[i][t] = true;
						col[j][t] = true;
						cell[i / 3 * 3 + j / 3][t] = true;
						if (sudoku(i, j, board))
						{
							return true;
						}
						else
						{
							row[i][t] = false;
							col[j][t] = false;
							cell[i / 3 * 3 + j / 3][t] = false;
							continue;
						}

					}
				}

				board[i][j] = '.';
				return false;
			}
		}

		return true;
	}

	
	bool row[9][9];
	bool col[9][9];
	bool cell[9][9];
};

int main()
{
	vector<vector<char>> v= {
		{'.','.','9','7','4','8','.','.','.'},
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' },
		{ '.','.','9','7','4','8','.','.','.' }
	};

	Solution s;
	s.solveSudoku(v);


    return 0;
}

