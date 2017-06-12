// First Missing Positive.cpp : Defines the entry point for the console application.
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
	int firstMissingPositive(vector<int>& nums) {
		unordered_map<int, bool> mp;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] <= 0) continue;

			mp[nums[i]] = true;
		}

		if (mp.size() == 0) return 1;
		int i = 1;
		for (; i <= nums.size(); i++)
		{
			if (mp.find(i) == mp.end()) return i;
		}

		if (i == nums.size() + 1) return i;

		return 1;
	}
};

class Solution2 {
public:
	int firstMissingPositive(vector<int>& nums) {
		nums.push_back(0);
		int n = (int)nums.size();
		for (int i = 0; i < n;) {
			if (nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i]]) {
				swap(nums[i], nums[nums[i]]);
			}
			else {
				i++;
			}
		}
		for (int i = 1; i < n; ++i) {
			if (nums[i] != i) {
				return i;
			}
		}
		return n;
	}
};

int main()
{
    return 0;
}

