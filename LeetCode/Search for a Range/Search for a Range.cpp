// Search for a Range.cpp : Defines the entry point for the console application.
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
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size() == 0) return {-1, -1};

		int low = 0, high = nums.size();
		int mid = 0;
		while (low < high)
		{
			mid = (low + high) >> 1;

			if (nums[mid] == target)
			{
				vector<int> ret;
				int l = mid, r = mid;
				while (l >= 1 && nums[l-1] == nums[mid]) l--;
				while (r+1 < nums.size() && nums[r+1] == nums[mid]) r++;
				ret.push_back(l);
				ret.push_back(r);
				return ret;
			}
			else if (nums[mid] < target)
			{
				low = mid+1;
				while (low < nums.size() && nums[low] == nums[mid])low++;
			}
			else
			{
				high = mid;
				while (high >= 1 && nums[high] == nums[high-1])high--;
			}
		}

		return{ -1, -1 };
	}
};


int main()
{
	vector<int> v = { 1,2,5,5,5,6,6,7,7,8,8,8,9 };
	Solution s;
	s.searchRange(v, 4);
    return 0;
}

