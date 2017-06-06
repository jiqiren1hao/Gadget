// Next Permutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() <= 1) return;

		bool fDone = false;
		for (int i = nums.size() - 1; i >= 0; i--)
		{
			int t = find(nums, i);
			if (t != -1)
			{
				int temp = nums[i];
				nums[i] = nums[t];
				nums[t] = temp;

				sort(nums.begin()+(i + 1), nums.end());
				fDone = true;
				break;
			}
		}

		if (!fDone) sort(nums.begin(), nums.end());
	}

	int find(vector<int>& v, int index)
	{
		int ret = -1;
		int max = INT_MAX;
		int t = v[index];
		for (int i = index + 1; i < v.size(); i++)
		{
			if (v[i] > t && v[i] < max)
			{
				ret = i;
				max = v[i];
			}
		}

		return ret;
	}
};


class Solution2 {
public:
	void nextPermutation(vector<int>& nums) {
		int n = nums.size();
		int i = n - 2;
		for (i = n - 2; i >= 0; i--)
		{
			if (nums[i] < nums[i + 1])
			{
				break;
			}
		}

		if (i == -1)
		{
			sort(nums.begin(), nums.end());
			return;// nums;
		}

		for (int j = n - 1; j > i; j--)
		{
			if (nums[j] > nums[i])
			{
				swap(nums[j], nums[i]);
				sort(nums.begin() + i + 1, nums.end());
				return;
			}
		}
		//return nums;
	}
};

int main()
{
	Solution s;
	vector<int> v = { 1,2,3 };
	s.nextPermutation(v);
    return 0;
}

