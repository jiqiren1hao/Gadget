// Longest Substring Without Repeating Characters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		size_t len = s.length();
		int nMax = 0;

		for (size_t i = 0; i < len; i++)
		{
			size_t j = i + 1;
			reset();
			int nTemp = 1;
			set(s[i]);
			for (; j < len; j++)
			{
				if (test(s[j]))
				{
					break;
				}
				set(s[j]);
				nTemp++;
			}

			if (nTemp > nMax) nMax = nTemp;
		}

		return nMax;

	}

	bool m_fMap[256];
	int GetIndex(char c)
	{
		return c - 'a';
	}
	void reset()
	{
		memset(m_fMap, 0, sizeof(m_fMap));
	}
	void set(char c)
	{
		m_fMap[c] = true;
	}
	bool test(char c)
	{
		return m_fMap[c];
	}
};

int lengthOfLongestSubstring(string s) {
	// for ASCII char sequence, use this as a hashmap
	vector<int> charIndex(256, -1);
	int longest = 0, m = 0;

	for (int i = 0; i < s.length(); i++) {
		m = max(charIndex[s[i]] + 1, m);    // automatically takes care of -1 case
		charIndex[s[i]] = i;
		longest = max(longest, i - m + 1);
	}

	return longest;
}

int main()
{
	Solution s;
	s.lengthOfLongestSubstring("abcbbdc");

    return 0;
}

