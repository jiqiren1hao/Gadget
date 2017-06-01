// Longest Common Prefix.cpp : Defines the entry point for the console application.
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
	static bool comp(string& s1, string& s2)
	{
		return s1.length() < s2.length();
	}

	string longestCommonPrefix(vector<string>& strs) {
		int size = strs.size();
		if (size == 0) return "";
		if (size == 1) return strs[0];

		sort(strs.begin(), strs.end(), comp);
		int n = strs[0].size();
		string s;
		for (int i = 0; i < n; i++)
		{
			bool fFind = true;
			for (int j = 1; j < size; j++)
			{
				if (strs[j][i] != strs[0][i])
				{
					fFind = false;
					break;
				}
			}
			
			if (fFind) s += strs[0][i];
			else break;
		}

		return s;
	}
};

class Solution2 {
public:
	string commonPre(string s1, string s2) {
		int len = s1.size() < s2.size() ? s1.size() : s2.size();
		int i = 0;
		while (s1[i] == s2[i] && i < len) {
			i++;
		}

		return s1.substr(0, i);
	}

	string longestCommonPrefix2(vector<string>& strs) {

		if (strs.size() == 0) {
			return "";
		}

		string pre = strs[0];
		for (int i = 1; i < strs.size(); i++) {
			pre = commonPre(pre, strs[i]);
		}
		return pre;
	}
};

class Solution3 {
public:
	string longestCommonPrefix(vector<string>& strs) {

		if (strs.size() == 0) return "";

		string s0, s;
		int lcp;
		int i, j;

		s0 = strs[0];
		lcp = strs[0].length();

		for (i = 1; i<strs.size(); i++) {
			s = strs[i];
			for (j = 0; j<s.length() && j<lcp; j++) {
				if (s0[j] != s[j]) {
					lcp = j;
					break;
				}
			}
			if (j<lcp)lcp = j;
		}
		return s0.substr(0, lcp);
	}
};

int main()
{
	Solution s;
	vector<string> v = { "aca", "cba" };
	s.longestCommonPrefix(v);
    return 0;
}

