// Search Insert Position.cpp : Defines the entry point for the console application.
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
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0) return 0;
		int low = 0, high = nums.size() - 1;
		int mid = (low + high) >> 1;

		while (low < high)
		{
			if (nums[mid] == target) return mid;
			else if (nums[mid] < target)low = mid + 1;
			else high = mid;

			mid = (low + high) >> 1;
		}

		return (nums[mid] >= target) ? mid : mid+1;
	}
};

class Solution2 {
public:
	int searchInsert(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (nums[mid] == target)
			{
				return mid;
			}
			else if (nums[mid] > target)
			{
				if (nums[mid - 1] < target)
				{
					return mid;
				}
				right = mid - 1;
			}
			else
			{
				if (nums[mid + 1] > target)
				{
					return mid + 1;
				}
				left = mid + 1;
			}
		}
		return left;
	}
};

int main()
{
	vector<int> v = { 1 };
	Solution s;
	s.searchInsert(v, 2);
    return 0;
}

