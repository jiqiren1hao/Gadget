// Add Binary.cpp : Defines the entry point for the console application.
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
	string addBinary(string a, string b) {
		if (a.size() == 0) return b;
		if (b.size() == 0) return a;

		int i = a.size() - 1, j = b.size() - 1;
		int carry = 0;
		string ret;
		ret.resize(max(i, j) + 2);
		int k = ret.size() - 1;

		for (; i >= 0 || j >= 0; i--, j--, k--)
		{
			int aa = i >= 0 ? a[i] - '0' : 0;
			int bb = j >= 0 ? b[j] - '0' : 0;
			int t = aa + bb + carry;
			if (t >= 2)
			{
				carry = 1;
				t = t - 2;
			}
			else
			{
				carry = 0;
			}
			ret[k] = t + '0';
		}

		if (carry == 1)ret[0] = '1';
		else ret = ret.substr(1, ret.size());

		return ret;
	}
};


class Solution2
{
public:
	string addBinary(string a, string b)
	{
		string s = "";

		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while (i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			s = char(c % 2 + '0') + s;
			c /= 2;
		}

		return s;
	}
};

int main()
{
	Solution s;
	s.addBinary("0", "0");
    return 0;
}

