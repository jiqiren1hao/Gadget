// Reverse Integer.cpp : Defines the entry point for the console application.
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
	int reverse(int x) {
		//2147483647
		//-2147483648
		if (x / 10 == 0) return x;
		vector<int> max = { 2,1,4,7,4,8,3,6,4,7 };
		int nMaxSize = max.size();
		vector<int> bits(nMaxSize, 0);
		int nCur = x;
		bool fPositive = true;
		
		if (x < 0)
		{
			max[nMaxSize - 1]++;
			fPositive = false;
			nCur = -nCur;
		}

		int nRet = 0;
		int index = 0;
		
		while (nCur > 0)
		{
			int base = 10;
			int right = nCur % base;
			nCur /= base;
			bits[index++] = right;
			if (index > nMaxSize)
			{
				// over flow
				return 0;
			}
		}
		--index;
		
		bool fMayOverFlow = (index == nMaxSize-1);;
		for (int i = 0; i <= index; i++)
		{
			if (fMayOverFlow)
			{
				if (bits[i] > max[i]) return 0;
				else if (bits[i] < max[i]) fMayOverFlow = false;
			}

			int nBase = pow(10, index-i);
			nRet += bits[i] * nBase;
		}

		return fPositive ? nRet : -nRet;
	}
};

class Solution2 {
public:
	int reverse(int x) {
		int res = 0;
		while (x != 0) {
			int t = res * 10 + x % 10;
			if (t / 10 != res)
			{
				return 0;
			}
			res = t;
			x /= 10;
		}
		return res;
	}
};

class Solution3 {
public:
	int reverse(int x) {
		if (x == INT_MIN)
			return 0;
		bool sign = (x >= 0);
		x = x * (sign ? 1 : -1);
		long long rev = 0;
		while (x) {
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		if (rev > INT_MAX)
			return 0;
		else
			return rev * (sign ? 1 : -1);
	}
};

int main()
{
	
	Solution3 s;
	s.reverse(1000000003);

    return 0;
}

