// Word Search.cpp : Defines the entry point for the console application.
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
	bool exist(vector<vector<char>>& board, string word) {
		if (word.length() == 0) return false;
		rows = board.size();
		if (rows == 0) return false;
		cols = board[0].size();
		if (cols == 0) return false;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (board[i][j] == word[0])
				{
					char t = board[i][j];
					board[i][j] = '#';
					if (find(board, i, j, word, 1)) return true;
					board[i][j] = t;
				}
			}
		}

		return false;
	}

	bool find(vector<vector<char>>& board, int bi, int bj, string word, int index)
	{
		if (index == word.length()) return true;

		// up
		if (bi > 0 && board[bi - 1][bj] == word[index])
		{
			char t = board[bi - 1][bj];
			board[bi - 1][bj] = '#';
			if (find(board, bi-1, bj, word, index + 1)) return true;
			board[bi - 1][bj] = t;
		}

		// down
		if (bi < rows - 1 && board[bi + 1][bj] == word[index])
		{
			char t = board[bi + 1][bj];
			board[bi + 1][bj] = '#';
			if (find(board, bi + 1, bj, word, index + 1)) return true;
			board[bi + 1][bj] = t;
		}

		// left
		if (bj>0 && board[bi][bj-1] == word[index])
		{
			char t = board[bi][bj-1];
			board[bi][bj-1] = '#';
			if (find(board, bi, bj-1, word, index + 1)) return true;
			board[bi][bj-1] = t;
		}

		// right
		if (bj<cols-1 && board[bi][bj + 1] == word[index])
		{
			char t = board[bi][bj + 1];
			board[bi][bj + 1] = '#';
			if (find(board, bi, bj + 1, word, index + 1)) return true;
			board[bi][bj + 1] = t;
		}

		return false;
	}

	int rows, cols;
};


int main()
{
    return 0;
}

