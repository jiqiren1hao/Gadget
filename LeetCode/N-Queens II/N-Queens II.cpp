// N-Queens II.cpp : Defines the entry point for the console application.
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
	int totalNQueens(int n) {
		size = n;
		string s;
		ret = 0;
		s.resize(size, '.');
		t.resize(size, s);
		col.resize(size, false);
		left.resize(2 * (size - 1) + 1, false);
		right.resize(2 * (size - 1) + 1, false);

		find(0);

		return ret;
	}

	void find(int row)
	{
		if (row == size)
		{
			ret++;
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
		if (i <= size - (j + 1))
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
	int ret;
	vector<bool> col;
	vector<bool> left;
	vector<bool> right;
};


class Solution {
public:
	int totalNQueens(int inputN) {
		n = inputN;
		ans = 0;
		find(0, 0, 0, 0);
		return ans;
	}

private:
	void find(uint64_t lmask, uint64_t vmask, uint64_t rmask, int row) {
		if (row == n) {
			++ans;
			return;
		}

		uint64_t mask = lmask | vmask | rmask;
		uint64_t cur = 1;
		for (int i = 0; i < n; ++i, cur <<= 1) {
			if ((mask & cur) != 0) {
				continue;
			}

			find((lmask | cur) << 1,
				(vmask | cur),
				(rmask | cur) >> 1,
				row + 1);
		}
	}

	int n;
	int ans;
};

int main()
{
    return 0;
}

