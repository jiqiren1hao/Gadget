// Regular Expression Matching.cpp : Defines the entry point for the console application.
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
		return match(s, p);
	}

	bool match(string s, string p)
	{
		if (s.empty() && p.empty()) return true;
		if (s.empty() != p.empty())
		{
			if (p.empty()) return false;
			else if(p.length() < 2 || p[1] != '*') return false;
		}

		if (1 < p.length() && p[1] == '*')
		{
			string t = p.substr(2, p.length());
			for (int i = 0; ; i++)
			{
				string tt;
				for (int k = 0; k < i; k++)
				{
					tt += p[0];
				}

				if (tt.length() > s.length())
				{
					break;
				}

				if (match(s, tt.append(t)))
				{
					return true;
				}
			}
			
			return false;
		}
		else
		{
			if (s[0] == p[0])
			{
				return match(s.substr(1, s.length()), p.substr(1, p.length()));
			}
			else if (p[0] == '.')
			{
				return match(s.substr(1, s.length()), p.substr(1, p.length()));
			}
			else
			{
				return false;
			}
		}		
	}
};

class Solution3 {
public:
	bool isMatch(string s, string p) {
		int m = s.length(), n = p.length();
		vector<vector<bool> > dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] == '*')
				{
					dp[i][j] = ((dp[i][j - 2]) || 
								(i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]));
				}

				else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				return dp[m][n];
	}
};

int main()
{
	Solution s;
	s.isMatch("", "c*c*");
    return 0;
}

