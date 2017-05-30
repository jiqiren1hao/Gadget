// ZigZag Conversion.cpp : Defines the entry point for the console application.
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
	string convert(string s, int numRows) {
		if (s.length() == 0 || numRows <= 1) return s;

		int n = numRows;
		vector<int> len(n);
		vector<int> start(n);
		int round = (n - 2) + n;
		int size = s.length();
		int cnt = size / round;
		int remain = size%round;
		int edge = (n - 1)*cnt;
		char* ret = new char[size + 1];
		memset(ret, 0, size+1);

		len[0] = cnt + (remain > 0 ? 1 : 0);
		start[0] = 0;

		for (int i = 1; i<=n - 2; i++)
		{
			len[i] = cnt * 2;
			if (remain >= i + 1)
			{
				len[i]++;
				if ((remain-n)%n >= n -1 - i)
				{
					len[i]++;
				}
			}

			start[i] = start[i - 1] + len[i - 1];
		}
		start[n - 1] = start[n - 2] + len[n - 2];

		bool direction = true;
		vector<int> k(n, 0);
		for (int i = 0, j = 0; i<size; i++)
		{
			ret[start[j] + k[j]] = s[i];
			k[j]++;
			if (direction)
			{
				j++;
				if (j == n)
				{
					direction = false;
					j -= 2;
				}
			}
			else
			{
				j--;
				if (j == -1)
				{
					direction = true;
					j += 2;
				}
			}
		}

		s.assign(ret);
		delete[] ret;
		return s;
	}
};


class Solution2 {
public:
	string convert(string s, int numRows) {
		if (numRows <= 1)
			return s;
		int step = (numRows - 1) * 2;
		string res;
		res.reserve(s.size());
		for (int i = 0; i < s.size(); i += step)
			res.push_back(s[i]);
		for (int i = 1; i < numRows - 1; ++i) {
			int steps[2] = { (numRows - i - 1) * 2,i*2 };
			int j = i;
			int k = 0;

			while (j < s.size()) {
				res.push_back(s[j]);
				j += steps[k % 2];
				++k;
			}
		}
		for (int i = numRows - 1; i < s.size(); i += step)
			res.push_back(s[i]);
		return res;
	}
};
int main()
{
	Solution2 s;
	s.convert("abcdefghijklm", 4);
    return 0;
}

