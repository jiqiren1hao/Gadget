// Count and Say.cpp : Defines the entry point for the console application.
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
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		string ret = "1";
		int i = 2;
		while (i<=n)
		{
			ret = say(ret);
			i++;
		}

		return ret;
	}

	string say(string s)
	{
		string ret;
		if (s.length() == 1)
		{
			ret.append("1");
			ret += s[0];
			return ret;
		}

		for (int i = 0; i < s.length();)
		{
			int t = s[i];
			int n = i;
			while (i < s.length() && s[i] == t) i++;
			string m = to_string(i - n);
			m += s[i - 1];
			ret += m;
		}

		return ret;
	}

};

string countAndSay(int n) {
	if (n == 0) return "";
	string res = "1";
	while (--n) {
		string cur = "";
		for (int i = 0; i < res.size(); i++) {
			int count = 1;
			while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
				count++;
				i++;
			}
			cur += to_string(count) + res[i];
		}
		res = cur;
	}
	return res;
}

int main()
{
	Solution s;
	s.countAndSay(10);
    return 0;
}

