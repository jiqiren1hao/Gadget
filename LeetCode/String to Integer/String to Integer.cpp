// String to Integer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

// "+1"
// "010"
// "   123"
// "    +004500"
// "+-2"
// "+"
// "9223372036854775809"

class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0)return 0;
		char* pHead = &str[0];
		int nStart = '0';
		bool fPositive = true;

		while (pHead != nullptr && *pHead == ' ') pHead++;
		if (*pHead == '+')
		{
			pHead++;
		}
		else if (*pHead == '-')
		{
			fPositive = false;
			pHead++;
		}

		while (pHead != nullptr && (*pHead == '0'))pHead++;

		long long nRet = 0;
		int nLength = 0;

		while (pHead != nullptr)
		{
			int nCur = *pHead - nStart;
			if (nCur > 9 || nCur < 0)
			{
				break;
			}

			nRet = nRet * 10 + nCur;
			++pHead;
			nLength++;
			if (nLength >= 11)
			{
				break;
			}
		}

		return fPositive ? (nRet > INT_MAX ? INT_MAX: nRet) : (-nRet < INT_MIN?INT_MIN:-nRet);
	}
};

// "+-2" output -2
class Solution2 {
public:
	int myAtoi(string str) {
		if (str.length() == 0)return 0;
		char* pHead = &str[0];
		int nStart = '0';
		bool fPositive = true;
		int nRet = 0;

		while (pHead != nullptr && *pHead != '\0')
		{
			int nCur = *pHead - nStart;
			if (nCur <= 9 && nCur > 0)
			{
				break;
			}

			if (*pHead == '+' || *pHead == ' ' || *pHead == '0')
			{
				pHead++;
				continue;
			}
			
			if (*pHead == '-')
			{
				fPositive = !fPositive;
				pHead++;
				continue;
			}
		}

		while (pHead != nullptr && *pHead != '\0')
		{
			int nCur = *pHead - nStart;
			if (nCur > 9 || nCur < 0)
			{
				break;
			}

			nRet = nRet * 10 + nCur;
			++pHead;
		}

		return fPositive ? nRet : -nRet;;
	}
};

// fasters
class Solution3 {
public:
	int myAtoi(string str) {
		int sign = 1, base = 0, i = 0;
		while (str[i] == ' ') { i++; }
		if (str[i] == '-' || str[i] == '+') {
			sign = 1 - 2 * (str[i++] == '-');
		}
		while (str[i] >= '0' && str[i] <= '9') {
			if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
				if (sign == 1)
				{
					return INT_MAX;
				}
				else
				{
					return INT_MIN;
				}
			}
			base = 10 * base + (str[i++] - '0');
		}
		return base * sign;
	}
};
int main()
{

	Solution3 s;
	s.myAtoi("2147483648");
    return 0;
}

