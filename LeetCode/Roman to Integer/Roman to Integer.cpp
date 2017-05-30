// Roman to Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;
/*
construct[0] = { "", "I","II","III","IV","V","VI","VII","VIII","IX" };
construct[1] = { "", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
construct[2] = { "", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
construct[3] = { "", "M","MM","MMM" };
*/

class Solution {
public:
	int romanToInt(string s) {
		int size = s.length();
		if (size <= 0) return 0;
		vector<int> base(26, 0);
		base['i' - 'a'] = 1;
		base['v' - 'a'] = 5;
		base['x' - 'a'] = 10;
		base['l' - 'a'] = 50;
		base['c' - 'a'] = 100;
		base['d' - 'a'] = 500;
		base['m' - 'a'] = 1000;

		int ret = 0;
		for (int i = 0; i < size;)
		{
			int n = base[s[i] - 'A'];

			if ((s[i] == 'I' && i + 1< size && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
				(s[i] == 'X' && i + 1< size && (s[i + 1] == 'L' || s[i + 1] == 'C')) ||
				(s[i] == 'C' && i + 1< size && (s[i + 1] == 'D' || s[i + 1] == 'M')))
			{
				ret += base[s[i+1] - 'A'] - base[s[i] - 'A'];
				i += 2;
			}
			else
			{
				ret += base[s[i] - 'A'];
				i++;
			}
		}

		return ret;
	}
};

int main()
{
	Solution s;
	s.romanToInt("MCMXCVI");
    return 0;
}

