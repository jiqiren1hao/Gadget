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

class Solution2 {
public:
	vector<string> result;
	void helper(string s, int leftpare_need, int moreleft)
	{
		if (leftpare_need == 0 && moreleft == 0) 
		{
			result.push_back(s);
			return;
		}
		if (leftpare_need > 0)
			helper(s + "(", leftpare_need - 1, moreleft + 1);
		if (moreleft > 0)
			helper(s + ")", leftpare_need, moreleft - 1);
	}
	vector<string> generateParenthesis(int n) {
		helper("", n, 0);
		return result;
	}
};

class Solution3 {
public:
	vector<string> result;
	void helper(string s, int l, int r)
	{
		if (l == 0 && r == 0) result.push_back(s);

		if (l > 0) helper(s + '(', l - 1, r + 1);
		if (r > 0) helper(s + ')', l, r - 1);

	}
	vector<string> generateParenthesis(int n) {
		helper("", n, 0);
		return result;
	}
};


int main()
{
	Solution3 s;

	s.generateParenthesis(5);
    return 0;
}

