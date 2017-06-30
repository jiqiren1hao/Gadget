// Permutation Sequence.cpp : Defines the entry point for the console application.
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
	string getPermutation(int n, int k) {
		string ret;
		if (k <= 0 || k > jiecheng(n)) return ret;

		num.resize(n, 0);
		for (int i = 0; i < n; i++) num[i] = i + 1;
		k--; // transfer to index, not the number
		int ind = 0;
		int i = 0;
		while (n)
		{
			int j = jiecheng(n - 1);
			ind = k / j;
			ret += getNum(ind) + '0';
			n = n - 1;
			k = k%j;
		}

		return ret;
	}

	int jiecheng(int n)
	{
		int ret = 1;
		for (int i = 2; i <= n; i++)
		{
			ret *= i;
		}

		return ret;
	}

	int getNum(int index)
	{
		int cnt = 0;
		for (int i = 0; i < num.size(); i++)
		{
			if (num[i] == 0) continue;

			if (cnt == index)
			{
				int ret = num[i];
				num[i] = 0;
				return ret;
			}

			cnt++;
		}

		return 0;
	}

	vector<int> num;
};


class Solution2 {
public:
	string getPermutation(int n, int k) {
		int i, j, f = 1;
		string s(n, '0');
		for (i = 1; i <= n; i++) {
			f *= i;
			s[i - 1] += i; // make s become 1234...n
		}
		for (i = 0, k--; i<n; i++) {
			f /= n - i;
			j = i + k / f; // calculate index of char to put at s[i]
			char c = s[j];
			// remove c by shifting to cover up (adjust the right part).
			for (; j>i; j--)
				s[j] = s[j - 1];
			k %= f;
			s[i] = c;
		}
		return s;
	}
};


int main()
{
	Solution s;
	s.getPermutation(3, 4);
    return 0;
}

