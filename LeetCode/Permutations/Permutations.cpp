// Permutations.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> permute(vector<int>& nums) {
		size = nums.size();
		mp.resize(size, false);

		vector<int> cur(size, 0);
		find(nums, cur, 0);

		return ret;
	}

	void find(vector<int>& nums, vector<int>& cur, int index)
	{
		if (index == size)
		{
			ret.push_back(cur);
			return;
		}

		for (int i = 0; i < size; i++)
		{
			if (!mp[i])
			{
				cur[index] = nums[i];
				mp[i] = true;
				find(nums, cur, index + 1);
				mp[i] = false;
			}
		}
	}

public:
	int size;
	vector<vector<int>> ret;
	vector<bool> mp;
};

int main()
{
	vector<int> v = { 1,2,3 };
	Solution s;
	s.permute(v);
    return 0;
}

