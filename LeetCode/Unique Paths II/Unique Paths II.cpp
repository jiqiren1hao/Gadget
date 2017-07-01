// Unique Paths II.cpp : Defines the entry point for the console application.
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
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

		int row = obstacleGrid.size();
		if (row == 0) return 0;
		int col = obstacleGrid[0].size();
		if (col == 0) return 0;

		vector<vector<int>> dp(row, vector<int>(col, 0));

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (i == 0 && j == 0) dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : 1;
				else if (i == 0) dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i][j - 1];
				else if (j == 0) dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j];
				else dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[row - 1][col - 1];
	}
};

int main()
{
    return 0;
}

