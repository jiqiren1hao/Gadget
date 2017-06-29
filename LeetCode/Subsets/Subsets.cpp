// Subsets.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ret;
		vector<int> null;
		ret.push_back(null);

		for (int i = 0; i < nums.size(); i++)
		{
			int n = ret.size();
			for (int j = 0; j < n; j++)
			{
				vector<int> t = ret[j];
				t.push_back(nums[i]);
				ret.push_back(t);
			}
		}

		return ret;
	}
};


class Solution2 {
public:
	void recurse(vector<vector<int>>& res, vector<int> subset, int pos, vector<int>& nums)
	{
		res.push_back(subset);
		if (pos >= nums.size())return;
		for (int i = pos; i<nums.size(); i++)
		{
			subset.push_back(nums[i]);
			recurse(res, subset, i + 1, nums);
			subset.pop_back();
		}
		return;
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>>res;
		recurse(res, vector<int>(), 0, nums);
		return res;
	}
};

int main()
{
    return 0;
}

