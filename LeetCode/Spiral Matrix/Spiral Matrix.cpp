// Spiral Matrix.cpp : Defines the entry point for the console application.
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
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		int nr = matrix.size();
		vector<int> ret;
		if (nr < 1) return ret;
		int nc = matrix[0].size();
		int row, col;
		int n = min(nc, nr);

		for (int i = 0; i < n / 2; i++)
		{
			row = i;
			col = i;
			while (col < nc - (i + 1))
			{
				ret.push_back(matrix[row][col]);
				col++;
			}

			row = i;
			col = nc - (i + 1);
			while (row < nr-(i+1))
			{
				ret.push_back(matrix[row][col]);
				row++;
			}

			row = nr - (i + 1);
			col = nc - (i + 1);
			while (col > i)
			{
				ret.push_back(matrix[row][col]);
				col--;
			}

			row = nr - (i + 1);
			col = i;
			while (row > i)
			{
				ret.push_back(matrix[row][col]);
				row--;
			}
		}

		if (n % 2 != 0)
		{
			if (nr <= nc)
			{
				for (int i = nr / 2; i < nc - nr / 2; i++)
				{
					ret.push_back(matrix[nr/2][i]);
				}
			}
			else
			{
				for (int i = nc / 2; i < nr - nc / 2; i++)
				{
					ret.push_back(matrix[i][nc/2]);
				}
			}
		}

		return ret;
	}
};


class Solution2 {
public:
	vector<int> spiralOrder(vector<vector<int>>& m) {
		int row = 0, col = 0;
		vector<int> ans;
		int r = m.size();
		if (r == 0) return ans;

		int c = m[0].size();

		int row_min = 0, row_max = r - 1;
		int col_min = 0, col_max = c - 1;
		int i, j;

		while (1) {
			if (col_min > col_max || row_min > row_max) break;

			/* Col increment. */
			for (i = col_min; i <= col_max; i++) {
				ans.push_back(m[row_min][i]);
			}
			row_min++;
			if (row_min > row_max) break;

			/* Row increment. */
			for (i = row_min; i <= row_max; i++) {
				ans.push_back(m[i][col_max]);
			}
			col_max--;
			if (col_min > col_max) break;

			/*Col decrement. */
			for (i = col_max; i >= col_min; i--) {
				ans.push_back(m[row_max][i]);
			}
			row_max--;
			if (row_min > row_max) break;

			/* Row decrement. */
			for (i = row_max; i >= row_min; i--) {
				ans.push_back(m[i][col_min]);
			}
			col_min++;
		}

		return ans;
	}
};

int main()
{
    return 0;
}

