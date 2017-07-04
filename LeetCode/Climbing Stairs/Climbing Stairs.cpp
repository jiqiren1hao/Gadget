// Climbing Stairs.cpp : Defines the entry point for the console application.
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
	int climbStairs(int n) {
		if (n <= 0) return 0;
		if (n == 1) return 1;

		vector<int> dp(n+1, 1);

		for (int i = 2; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}

		return dp[n];
	}
};


int main()
{
    return 0;
}

