// Plus One.cpp : Defines the entry point for the console application.
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
	vector<int> plusOne(vector<int>& digits) {
		size_t s = digits.size();
		if (s == 0) return vector<int>(1, 1);

		vector<int> ret(s + 1, 0);
		int carry = 1;
		int i = s - 1;

		for (int j = s; i >= 0; i--, j--)
		{
			ret[j] = digits[i] + carry;
			if (ret[j] >= 10)
			{
				ret[j] -= 10;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
		}

		if (!carry)
		{
			vector<int> r(ret.begin() + 1, ret.end());
			return r;
		}

		ret[0] = carry;

		return ret;
	}
};

void plusone(vector<int> &digits)
{
	int n = digits.size();
	for (int i = n - 1; i >= 0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			return;
		}
	}
	digits[0] = 1;
	digits.push_back(0);

}

int main()
{
    return 0;
}

