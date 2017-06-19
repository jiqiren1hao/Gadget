// Trapping Rain Water.cpp : Defines the entry point for the console application.
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
	int trap(vector<int>& height) {
		int l = 0, r = height.size() - 1, level = 0, water = 0;
		while (l < r) {
			int lower = height[height[l] < height[r] ? l++ : r--];
			level = max(level, lower);
			water += level - lower;
		}
		return water;
	}
};

class Solution2 {
public:
	int trap(vector<int>& height) {
		int n = height.size();
		int left = 0; int right = n - 1;
		int res = 0;
		int maxleft = 0, maxright = 0;
		while (left <= right) {
			if (height[left] <= height[right]) {
				if (height[left] >= maxleft) maxleft = height[left];
				else res += maxleft - height[left];
				left++;
			}
			else {
				if (height[right] >= maxright) maxright = height[right];
				else res += maxright - height[right];
				right--;
			}
		}
		return res;
	}
};

int main()
{
	vector<int> v = {2,6,3,4,1,5};
	Solution s;
	s.trap(v);
    return 0;
}

