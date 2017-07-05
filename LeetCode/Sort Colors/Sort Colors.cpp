// Sort Colors.cpp : Defines the entry point for the console application.
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
	void sortColors(vector<int>& nums) {
		if (nums.size() <= 1) return;

		sort(nums, 0, nums.size() - 1);
	}

	void sort(vector<int>& nums, int start, int end)
	{
		if (start >= end) return;
		int c = sort2(nums, start, end);
		sort(nums, start, c - 1);
		sort(nums, c + 1, end);
	}

	int sort2(vector<int>& nums, int start, int end)
	{
		int p = start;
		int index = start;
		for (int i = start+1; i <= end; i++)
		{
			if (nums[i] <= nums[p])
			{
				swap(nums[index], nums[i]);
				if (index == p)	p = i;
				index++;
			}
		}

		swap(nums[p], nums[index]);
		return index;
	}
};

// Here I label the end of same colour, and update for every item in nums.
void sortColors(vector<int>& nums) {
	int r = 0, w = 0, b = 0; // label the end of different colors;
	for (int num : nums) {
		if (num == 0) { nums[b++] = 2; nums[w++] = 1; nums[r++] = 0; }
		else if (num == 1) { nums[b++] = 2; nums[w++] = 1; }
		else if (num == 2) b++;
	}
}

int main()
{
	vector<int> v = { 0,2,2,2,0,2,1,1 };
	Solution s;
	s.sortColors(v);
    return 0;
}

