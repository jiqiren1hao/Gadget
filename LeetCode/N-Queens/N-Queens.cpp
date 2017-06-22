// N-Queens.cpp : Defines the entry point for the console application.
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
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		size = n;
		string s;
		s.resize(size, '.');
		t.resize(size, s);
		col.resize(size, false);
		left.resize(2*(size-1)+1, false);
		right.resize(2 * (size - 1)+1, false);

		find(0);

		return ret;
	}

	void find(int row)
	{
		if (row == size)
		{
			ret.push_back(t);
			return;
		}

		for (int i = 0; i < size; i++)
		{
			int l = GetLeft(row, i);
			int r = GetRight(row, i);
			if (!col[i] && !left[l] && !right[r])
			{
				t[row][i] = 'Q';
				col[i] = true;
				left[l] = true;
				right[r] = true;

				find(row + 1);

				t[row][i] = '.';
				col[i] = false;
				left[l] = false;
				right[r] = false;
			}
		}
	}

	int GetLeft(int i, int j)
	{
		if (i <= size - (j+1))
		{
			while (i > 0)
			{
				i--;
				j++;
			}
		}
		else
		{
			while (i < size - 1)
			{
				i++;
				j--;
			}
		}

		return i + j;
	}

	int GetRight(int i, int j)
	{
		if (i <= j)
		{
			while (i > 0)
			{
				i--;
				j--;
			}
		}
		else
		{
			while (i < size - 1)
			{
				i++;
				j++;
			}

			if (j == 0 && i == size - 1) return 2 * (size - 1);
		}

		return i + j;
	}

	int size;
	vector<string> t;
	vector<vector<string>> ret;
	vector<bool> col;
	vector<bool> left;
	vector<bool> right;
};

int main()
{
	Solution s;
	s.solveNQueens(4);
    return 0;
}

