// Wildcard Matching.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int s1 = s.length();
		int s2 = p.length();

		vector<vector<bool>> dp(s1+1, vector<bool>(s2+1, false));
		dp[0][0] = true;

		for (int i = 0; i <= s1; i++)
		{
			for (int j = 1; j <= s2; j++)
			{
				if (p[j-1] == '*')
				{
					dp[i][j] = (dp[i][j - 1]) || (i>0 && dp[i - 1][j]);
				}
				else
				{
					dp[i][j] = (i > 0 && dp[i - 1][j - 1] && (s[i-1] == p[j-1] || p[j-1] == '?'));
				}
			}
		}

		return dp[s1][s2];
	}
};


bool isMatch(const char *s, const char *p) {
	const char* star = NULL;
	const char* ss = s;
	while (*s) {
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)) { s++; p++; continue; }

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*') { star = p++; ss = s; continue; }

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (star) { p = star + 1; s = ++ss; continue; }

		//current pattern pointer is not star, last patter pointer was not *
		//characters do not match
		return false;
	}

	//check for remaining characters in pattern
	while (*p == '*') { p++; }

	return !*p;
}

int main()
{

	Solution s;
	string a = "aab";
	string b = "c*a*b*";
	s.isMatch(a, b);
    return 0;
}

