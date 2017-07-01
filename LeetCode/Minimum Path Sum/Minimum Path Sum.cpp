// Minimum Path Sum.cpp : Defines the entry point for the console application.
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
	int minPathSum(vector<vector<int>>& grid) {
		int row = grid.size();
		if (row == 0) return 0;

		int col = grid[0].size();
		if (col == 0) return 0;

		vector<vector<int>> dp(row, vector<int>(col, INT_MAX));

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i == 0 && j == 0) dp[i][j] = grid[i][j];
				else if (i == 0) dp[i][j] = dp[i][j-1] + grid[i][j];
				else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
				else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}

		return dp[row - 1][col - 1];
	}
};


class Solution2 {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));

		dp[0][0] = grid[0][0];
		for (int i = 1; i<m; i++) dp[i][0] = grid[i][0] + dp[i - 1][0];
		for (int i = 1; i<n; i++) dp[0][i] = grid[0][i] + dp[0][i - 1];

		for (int i = 1; i<m; i++)
		{
			for (int j = 1; j<n; j++)
			{
				dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		return dp[m - 1][n - 1];
	}
};

int main()
{
    return 0;
}

