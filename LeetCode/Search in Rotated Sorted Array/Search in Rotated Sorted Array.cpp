// Search in Rotated Sorted Array.cpp : Defines the entry point for the console application.
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
	int search(vector<int>& nums, int target) {
		if (nums.size() == 0) return -1;
		
		int left = 0;
		int right = nums.size() - 1;
		int begin = nums[0];
		int end = nums[right];
		int mid=0;

		if (target > end && target < begin) return -1;

		while (left < right)
		{
			mid = (left + right) / 2;
			if (nums[mid] == target) return mid;

			if (begin > end)
			{
				if (nums[mid] > end)
				{
					if (nums[mid] > target)
					{
						if (target < begin)
						{
							// rigth
							left = mid + 1;
							begin = nums[left];
						}
						else
						{
							//left
							right = mid;
							end = nums[mid];
						}
					}
					else
					{
						// rigth
						left = mid + 1;
						begin = nums[left];
					}
				}
				else
				{
					if (nums[mid] < target)
					{
						if (target > end)
						{
							// left 
							right = mid;
							end = nums[mid];
						}
						else
						{
							left = mid + 1;
							begin = nums[left];
						}
					}
					else
					{
						// left
						right = mid;
						end = nums[mid];
					}
				}
			}
			else
			{
				if (nums[mid] < target)
				{
					// choose rigth
					left = mid+1;
					begin = nums[left];
				}
				else
				{
					// choose left
					right = mid;
					end = nums[mid];
				}
			}
		}

		mid = (left + right) / 2;
		if (nums[mid] == target) return mid;

		return -1;
	}
};

class Solution2 {
public:
	int search(vector<int>& nums, int target)
	{
		int i = nums.size() - 1;
		while (i > 0 && nums[i - 1] <= nums[i]) --i;
		int lo = 0, hi = nums.size();
		//tmid是按顺序排列的中间数在实际数组中的索引
		int mid = (lo + hi) >> 1, tmid = mid + i;
		if (tmid > nums.size() - 1) tmid = tmid - nums.size();
		while (lo < hi)
		{
			if (nums[tmid] < target) lo = mid + 1;
			else if (nums[tmid] > target) hi = mid;
			else return tmid;
			mid = (lo + hi) >> 1;
			tmid = mid + i;
			if (tmid > nums.size() - 1) tmid = tmid - nums.size();
		}
		return -1;
	}
};

int main()
{
	vector<int> v = { 4,5,6,7,8,1,2,3 };
	Solution s;
	s.search(v, 8);
    return 0;
}

