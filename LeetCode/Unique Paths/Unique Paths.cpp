// Unique Paths.cpp : Defines the entry point for the console application.
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

class Solution2 {
public:
	int uniquePaths(int m, int n) {
		mRow = m;
		mCol = n;

		return find(0, 0);
	}

	int find(int i, int j)
	{
		if (i == mRow-1 || j == mCol-1) return 1;
		if (i >= mRow || j >= mCol) return 0;

		return find(i + 1, j) + find(i, j + 1);
	}

	int mCol;
	int mRow;
};

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n, 0));

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j == 0) dp[i][j] = 1;
				else if (i == 0) dp[i][j] = dp[i][j - 1];
				else if (j == 0) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return dp[m - 1][n - 1];
	}
};


int main()
{
	Solution s;
	int n1 = s.uniquePaths(23, 14);

	Solution2 s2;
	int n2 = s2.uniquePaths(23, 14);

	if (n1 == n2) cout << "OK" << endl;
    return 0;
}

