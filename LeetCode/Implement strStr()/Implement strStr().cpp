// Implement strStr().cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <stack>
using namespace std;


class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.size() == 0) return 0;
		if (needle.size() > haystack.size()) return -1;
		char c = needle[0];
		for (int i = 0; i <= haystack.size() - needle.size();)
		{
			if (haystack[i] == c)
			{
				int t = i, j = 1;
				for (; t + j<haystack.size() && j < needle.size(); j++)
				{
					if (t == i && haystack[t + j] == c)
					{
						i = t + j;
					}
					if (haystack[t + j] != needle[j])
					{
						break;
					}
				}

				if (j == needle.size()) return t;
				if (t == i) i += j + 1;
			}
			else
			{
				i++;
			}
		}

		return -1;
	}
};

class Solution {
public:
	int strStr(string haystack, string needle) {
		int i, j, k;
		if (haystack.size()<needle.size())
			return -1;
		for (i = 0; i <= (haystack.size() - needle.size()); i++) {
			for (j = 0, k = i; j<needle.size(); j++, k++) {
				if (needle[j] != haystack[k])
					break;
			}
			if (j == needle.size()) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	string s1 = "abbabaaaabbbaabaababbbbbbaa";
	string s2 = "bbbbbbaa";
	Solution s;
	s.strStr(s1, s2);
    return 0;
}

