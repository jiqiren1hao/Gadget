// Integer to Roman.cpp : Defines the entry point for the console application.
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
	string intToRoman(int num) {
		vector<vector<string>> base(4);
		base[0] = { "I", "V" };  // 10^0
		base[1] = { "X", "L" };  // 10^1
		base[2] = { "C", "D" };  // 10^2
		base[3] = { "M", "V" };  // 10^3

		vector<vector<string>> construct(4, vector<string>(10, ""));
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; (i!=3 && j < 10) || (i==3 && j<4); j++)
			{
				if (j == 4)
				{
					construct[i][j].append(base[i][0]);
					construct[i][j].append(base[i][1]);
				}
				else if (j == 9)
				{
					construct[i][j].append(base[i][0]);
					construct[i][j].append(base[i+1][0]);
				}
				else if(j == 5)
				{
					construct[i][j].append(base[i][1]);
				}
				else if (j < 5)
				{
					// 1,2,3
					for (int k = 1; k <= j; k++)
					{
						construct[i][j].append(base[i][0]);
					}
				}
				else
				{
					//6,7,8
					construct[i][j].append(base[i][1]);
					for (int k = 6; k <= j; k++)
					{
						construct[i][j].append(base[i][0]);
					}
				}
			}
		}

		string s;
		for (int i = 3; i >= 0; i--)
		{
			int p = pow(10, i);
			int n = num / p;
			if (n > 0)
			{
				s.append(construct[i][n]);
				num = num%p;
			}
		}

		return s;
	}
};

class Solution2 {
public:
	string intToRoman(int num) {
		vector<vector<string>> construct(4, vector<string>(10, ""));
		construct[0] = { "", "I","II","III","IV","V","VI","VII","VIII","IX" };
		construct[1] = { "", "X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
		construct[2] = { "", "C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
		construct[3] = { "", "M","MM","MMM" };

		string s;
		for (int i = 3; i >= 0; i--)
		{
			int p = pow(10, i);
			int n = num / p;
			if (n > 0)
			{
				s.append(construct[i][n]);
				num = num%p;
			}
		}

		return s;
	}
};

int main()
{
	Solution2 s;
	s.intToRoman(61);
    return 0;
}

