// Remove Duplicates from Sorted Array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <stack>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		if (nums.size() <= 1) return nums.size();
		int newLen = 1;
		int len = 1;

		for (; len < nums.size();len++)
		{
			
			if (nums[len] == nums[len - 1])
			{
				continue;
			}
			
			if (len != newLen)
			{
				nums[newLen] = nums[len];
			}
			newLen++;
		}

		return newLen;
	}
};

class Solution2 {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty()) return 0;
		int finder = 0;
		int copy = 0;
		while (finder < nums.size()) {
			while (finder < nums.size() - 1 && nums[finder] == nums[finder + 1]) finder++;
			nums[copy++] = nums[finder++];
		}
		return copy;
	}
};


int main()
{
	vector<int> v = { 0,1,2,2,2,3 };

	Solution s;
	s.removeDuplicates(v);
    return 0;
}

