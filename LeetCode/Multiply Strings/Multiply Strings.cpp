// Multiply Strings.cpp : Defines the entry point for the console application.
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
	string multiply(string num1, string num2) {
		string ret;
		
		for (int i = num2.size()-1, iter = 0; i >= 0; i--, iter++)
		{
			int t2 = num2[i] - '0';
			int add = 0;
			string iterRet;
			for (int j = num1.size()-1; j >= 0; j--)
			{
				int t1 = num1[j] - '0';
				int t = t1*t2+add;
				int c = t % 10;
				add = t / 10;
				iterRet += (c + '0');
			}

			if (add > 0) iterRet += (add + '0');

			// we got one iteration result here
			// add with previous result

			int a = 0;
			int k = iter, r = 0;
			for (; k < ret.size()&& r<iterRet.size(); k++,r++)
			{
				int t = (ret[k] - '0') + (iterRet[r] - '0')+a;
				ret[k] = ((t % 10)+'0');
				a = t / 10;
			}

			while (k < ret.size())
			{
				int t = (ret[k] - '0') + a;
				ret[k] = ((t % 10) + '0');
				a = t / 10;
				k++;
			}

			while (r < iterRet.size())
			{
				int t = (iterRet[r] - '0') + a;
				ret += ((t % 10)+'0');
				a = t / 10;
				r++;
			}

			if (a > 0) ret += (a + '0');
		}

		int i = ret.size()-1;
		while (i >= 0 && ret[i] == '0') i--;
		ret = ret.substr(0, i + 1);
		string s(ret.rbegin(), ret.rend());
		return s.size() > 0 ? s:"0";
	}
};

string multiply(string num1, string num2) {
	string sum(num1.size() + num2.size(), '0');

	for (int i = num1.size() - 1; 0 <= i; --i) {
		int carry = 0;
		for (int j = num2.size() - 1; 0 <= j; --j) {
			int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
			sum[i + j + 1] = tmp % 10 + '0';
			carry = tmp / 10;
		}
		sum[i] += carry;
	}

	size_t startpos = sum.find_first_not_of("0");
	if (string::npos != startpos) {
		return sum.substr(startpos);
	}
	return "0";
}

int main()
{
	Solution s;
	s.multiply("9133", "0");
    return 0;
}

