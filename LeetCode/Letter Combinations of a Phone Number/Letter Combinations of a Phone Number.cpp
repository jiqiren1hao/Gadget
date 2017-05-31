// Letter Combinations of a Phone Number.cpp : Defines the entry point for the console application.
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
	vector<string> letterCombinations(string digits) {
		vector<string> v;
		if (digits.length() == 0) return v;
		int n = digits[0] - '0';
		int size = key[n].length();

		if (digits.length() == 1)
		{
			for (int i = 0; i < size; i++)
			{
				string s;
				s += key[n][i];
				v.push_back(s);
			}

			return v;
		}

		vector<string> t = letterCombinations(digits.substr(1, digits.length()));
		for (int j = 0; j < t.size(); j++)
		{
			for (int k = 0; k < size; k++)
			{
				string s;
				s += t[k];
				s += key[n][k];
				v.push_back(s);
			}
		}

		return v;
	}

	string key[10] = {
		"",
		"",
		"abc",
		"def",
		"ghi",
		"jkl",
		"mno",
		"pqrs",
		"tuv",
		"wxyz"
	};
};


int main()
{
	Solution s;
	s.letterCombinations("5678");
    return 0;
}

