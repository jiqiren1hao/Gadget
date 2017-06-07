// Divide Two Integers.cpp : Defines the entry point for the console application.
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


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) return 0;
		if (!divisor || (dividend == INT_MIN &&divisor == -1)) return INT_MAX;
		long long d2 = labs(dividend);
		long long  d1 = labs(divisor);
		bool fSign = ((dividend<0) ^ (divisor>0)) ? true : false;

		long long n = d2;
		int len1 = 0, len2 = 0;

		while (n > 0)
		{
			n = n >> 1;
			len2++;
		}

		n = d1;
		while (n > 0)
		{
			n = n >> 1;
			len1++;
		}

		int diff = len2 - len1;
		long long  ret = 0;
		if (diff < 0) return 0;

		long long  base = (d2 >> diff);
		for (; diff >= 0;)
		{
			int d = base - d1;
			if (d >= 0)
			{
				ret += (1UL << diff);
				diff--;
				base = (d << 1) + ((d2&(1UL << diff)) > 0 ? 1 : 0);
			}
			else
			{
				diff--;
				base = (base << 1) + ((d2&(1UL << diff)) > 0 ? 1 : 0);
			}
		}

		return fSign ? ret : -ret;
	}
};

class Solution2 {
public:
	int divide(int dividend, int divisor) {
		if (!divisor || (dividend == INT_MIN &&divisor == -1)) return INT_MAX;
		int flag = ((dividend<0) ^ (divisor>0)) ? 1 : -1; //0:neg
		long long div = labs(dividend);
		long long  dis = labs(divisor);
		int res = 0;

		while (div >= dis)
		{
			long long tmp = dis, count = 1;
			while (div >= (tmp << 1))
			{
				tmp <<= 1;
				count <<= 1;
			}
			div -= tmp;
			res += count;
		}
		return res*flag;
	}
};


int main()
{
	Solution2 s;
	int a = 11;
	int b = 2;
	s.divide(a, b);
    return 0;
}

