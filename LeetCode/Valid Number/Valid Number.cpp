// Valid Number.cpp : Defines the entry point for the console application.
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

class Solution {
public:
	bool isNumber(string s) {
		bool dot=false, sign=false, e=false, num=false;
		int i = 0, j=s.size()-1;
		while (i < s.size() && s[i] == ' ') i++;
		while (j >= 0 && s[j] == ' ') j--;

		for (; i <= j; i++)
		{
			if (s[i] == '+' || s[i] == '-')
			{
				if (sign || num || dot) return false;
				sign = true;
			}
			else if (s[i] == 'e')
			{
				if (e||!num) return false;
				e = true;
				sign = false;
				num = false;
				dot = false;
			}
			else if (s[i] == '.')
			{
				if (dot || e)return false;
				dot = true;
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				num = true;
			}
			else
			{
				return false;
			}
		}

		return num;
	}
};

int main()
{
	Solution s;
	s.isNumber("0.5e-9.0");

    return 0;
}

