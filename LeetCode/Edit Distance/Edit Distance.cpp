// Edit Distance.cpp : Defines the entry point for the console application.
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
	int minDistance(string word1, string word2) {
		if (word1.length() == 0) return word2.length();
		if (word2.length() == 0) return word1.length();

		vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));

		for (int i = 0; i <= word1.length(); i++)
		{
			for (int j = 0; j <= word2.length(); j++)
			{
				if (i == 0)dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else
				{
					int t1 = min(dp[i - 1][j - 1] + (word1[i-1] == word2[j-1] ? 0 : 1), dp[i - 1][j]+1);
					dp[i][j] = min(t1, dp[i][j-1]+1);
				}
			}
		}

		return dp[word1.length()][word2.length()];
	}
};


int main()
{
	Solution s;
	string s1 = "sea";
	string s2 = "ate";
	s.minDistance(s1, s2);
    return 0;
}

