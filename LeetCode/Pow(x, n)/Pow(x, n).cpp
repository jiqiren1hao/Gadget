// Pow(x, n).cpp : Defines the entry point for the console application.
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
	double myPow(double x, int n) {

		long long m = n;
		if (m < 0)
		{
			x = 1 / x;
			m = -m;
		}

		if (m == 1) return x;
		if (m == 0) return 1.0;

		if (m % 2 == 0)
		{
			return myPow(x*x, m / 2);
		}
		else
		{
			m -= 1;
			return myPow(x*x, m / 2)*x;
		}
	}
};

class Solution {
public:
	double myPow(double x, int n) {

		long long m = n;
		if (m < 0)
		{
			x = 1 / x;
			m = -m;
		}

		if (m == 1) return x;
		if (m == 0) return 1.0;

		double ret = x;
		double ret2 = 1;
		double r2 = 1;

		while (m > 0)
		{
			if (m % 2 != 0)
			{
				r2 = ret;
				m -= 1;
				continue;
			}

			ret *= ret;
			ret2 *= r2;
			m = m / 2;
			r2 = 1;
		}

		return ret*ret2;
	}
};

int main()
{
	Solution s;
	s.myPow(2, 4);
    return 0;
}

