// 3Sum Closest.cpp : Defines the entry point for the console application.
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
	int find(vector<int>& v, int index, int target)
	{
		int ret;
		int del = INT_MIN;
		long long absDel = llabs(del);
		for (int i = 0, j = v.size() - 1; i < j;)
		{
			if (i == index)
			{
				i++;
				continue;
			}
			if (j == index)
			{
				j--;
				continue;
			}
			int t = v[i] + v[j];
			int tt = t - target;
			if (llabs(tt) < absDel)
			{
				ret = t;
				del = tt;
				absDel = llabs(tt);
			}

			if (tt > 0) j--;
			else if (tt < 0) i++;
			else return target;
		}

		return ret;
	}

	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return 0;
		if (nums.size() == 3)return nums[0] + nums[1] + nums[2];
		
		sort(nums.begin(), nums.end());
		int ret;
		long long absDel = llabs(INT_MIN);

		for (int i = 0; i < nums.size();)
		{
			int c = nums[i];
			int t = target - c;
			int r = find(nums, i, t);

			int tt = r + c;
			if (tt == target) return target;
			long long absCur = llabs(target - tt);
			if (absCur < absDel)
			{
				absDel = absCur;
				ret = r + c;
			}

			while (i < nums.size() && nums[i] == c) i++;
		}

		return ret;
	}
};

class Solution2 {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int res = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i<nums.size() - 2; i++) {
			int left = i + 1, right = nums.size() - 1;
			while (left<right) {
				int temp = nums[i] + nums[left] + nums[right];
				if (res == INT_MAX || (abs(temp - target)<abs(res - target))) res = temp;
				if (temp<target) left++;
				else if (temp>target) right--;
				else if (temp == target) return target;
			}
		}
		return res;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 0,2,1,-3 };
	s.threeSumClosest(v, 1);
    return 0;
}

