// Palindrome Number.cpp : Defines the entry point for the console application.
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
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x / 10 == 0) return true;
		for (long long i = pow(10, 10), j=10; i > 0;)
		{
			if (x / i == 0)
			{
				i = i / 10;
				continue;
			}
			if ((x%(i*10) / i == (x/(j/10) % 10)))
			{
				if (j * 10 == i || i==j)
				{
					return true;
				}

				i = i / 10;
				j = j * 10;
			}
			else
			{
				break;
			}
		}

		return false;
	}
};

// faster
class Solution2 {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int y = 0, z = x;
		while (z)
		{
			y = 10 * y + z % 10;
			z /= 10;
		}
		return x == y ? true : false;
	}
};

int main()
{
	Solution s;
	s.isPalindrome(9999);

    return 0;
}

