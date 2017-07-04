// Sqrt(x).cpp : Defines the entry point for the console application.
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
	int mySqrt(int x) {
		long long l = 0, r = x;
		long long mid = 0;
		int ret = 0;
		while (l < r)
		{
			mid = (l + r) / 2;
			long long t = mid*mid;
			if (t == x) return mid;
			else if (t < x)
			{
				if (t < x && t > ret) ret = mid;
				l = mid + 1;
			}
			else r = mid;
		}

		mid = (l + r) / 2;
		long long t = mid*mid;
		if (t == x) ret = mid;
		else if (t < x && t > ret) ret = mid;
		return ret;
	}
};

class Solution2 {
public:
	int sqrt(int x) {
		if (0 == x) return 0;
		int left = 1, right = x, ans;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (mid <= x / mid) {
				left = mid + 1;
				ans = mid;
			}
			else {
				right = mid - 1;
			}
		}
		return ans;
	}
};

/*

long r = x;
while (r*r > x)
r = (r + x/r) / 2;
return r;

*/


int main()
{
	Solution s;
	s.mySqrt(2147395599);
    return 0;
}

