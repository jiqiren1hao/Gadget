// Jump Game II.cpp : Defines the entry point for the console application.
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
	int jump(vector<int>& nums) {
		int s = nums.size();
		if (s <= 1) return 0;

		vector<int> v(s, INT_MAX);
		v[s - 1] = 0;
		int dis = 0;

		for (int i = s - 2; i >= 0; i--)
		{
			int step = nums[i] == 0 ? 0:1;
			int target = i + nums[i];
			if (target < s-1) step += v[target];

			if (step >= 0 && step < INT_MAX)
			{
				v[i] = step;
				int j = i+1;
				while (j < s && v[j] > step) v[j++] = step;
			}
		}

		return v[0];
	}
};


class Solution {
public:
	int jump(vector<int>& nums) {
		int cur = 0, i = 0, n = nums.size(), res = 0;
		while (cur < n - 1)
		{
			int pre = cur;
			while (i <= pre)
			{
				cur = max(cur, i + nums[i]);
				++i;
			}
			++res;
			if (pre == cur) return -1;
		}
		return res;
	}
};

int main()
{
	vector<int> v = { 2,3,1,1,4 };

	Solution s;
	s.jump(v);
    return 0;
}

