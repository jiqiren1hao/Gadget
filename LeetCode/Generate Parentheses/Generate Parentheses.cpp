// Generate Parentheses.cpp : Defines the entry point for the console application.
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

bool isDup(vector<string>&v, string &s)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (s == v[i])return true;
	}
	return false;
}

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		string s;
		vector<string> v;
		for (int i = 0; i < n; i++)
		{
			s += '(';
		}

		for (int i = 0; i < n; i++)
		{
			s += ')';
		}
		v.push_back(s);
		
		move(n - 1, s, v);

		return v;
	}

	void move(int index, string s, vector<string>& v)
	{
		for (int i = 1; i <= index; i++)
		{
			if (s[index] != '(' || s[index] == s[index + i]) continue;
			string cache = s.substr(0, index) + s.substr(index+1, i) + s[index] + s.substr(index+i+1, s.length()-(index+i)-1);

			if (isDup(v, cache))
			{
				cout << "OK" << endl;
			}
			v.push_back(cache);
			move(index - 1, cache, v);
		}
	}
};


int main()
{
	Solution s;

	s.generateParenthesis(5);
    return 0;
}

