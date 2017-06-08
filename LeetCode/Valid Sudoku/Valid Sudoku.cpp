// Valid Sudoku.cpp : Defines the entry point for the console application.
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
	bool isValidSudoku(vector<vector<char>>& board) {
		if (board.size() != 9) return false;

		vector<vector<bool>> row(9, vector<bool>( 9, false ));
		vector<vector<bool>> col(9, vector<bool>(9, false));
		vector<vector<bool>> cell(9, vector<bool>(9, false));

		for (int i = 0; i < 9; i++)
		{
			if (board[i].size() != 9) return false;
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == '.') continue;
				int t = board[i][j] - '0'-1;
				if (board[i][j] > '9' || board[i][j] < '1') return false;
				if (row[i][t] || col[j][t] || cell[i / 3 * 3 + j / 3][t]) return false;
				row[i][t] = true;
				col[j][t] = true;
				cell[i / 3 * 3 + j / 3][t] = true;
			}
		}

		return true;
	}
};

class Solution2 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rowValid[10] = { 0 };//用于判断某一行是否合法，对于行来说这个数组可以重复使用
		int columnValid[9][10] = { 0 };//用于判断某一列是否合法
		int subBoardValid[9][10] = { 0 };//用于判断某一个九宫格是否合法
		for (int i = 0; i < 9; i++)
		{
			memset(rowValid, 0, sizeof(rowValid));
			for (int j = 0; j < 9; j++)
				if (board[i][j] != '.')
				{
					if (!checkValid(rowValid, board[i][j] - '0') ||
						!checkValid(columnValid[j], board[i][j] - '0') ||
						!checkValid(subBoardValid[i / 3 * 3 + j / 3], board[i][j] - '0'))
						return false;
				}
		}
		return true;
	}
	bool checkValid(int vec[], int val)
	{
		if (vec[val] == 1)return false;
		vec[val] = 1;
		return true;
	}
};

int main()
{
    return 0;
}

