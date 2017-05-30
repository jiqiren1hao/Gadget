// Container With Most Water.cpp : Defines the entry point for the console application.
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
	int maxArea(vector<int>& height) {
		int size = height.size();
		if (size <= 1) return 0;
		int max = 0;

		for (int i = 0, j = size - 1; i < j; )
		{
			int nCur = (j - i)*min(height[i], height[j]);
			if (nCur > max) max = nCur;
			if (height[i] < height[j]) i++;
			else j--;
		}

		return max;
	}
};

class Solution2 {
public:
	int maxArea(vector<int>& height) {

		int sol = 0;
		int l = 0, r = height.size() - 1;

		while (l<r) {

			int temp = (r - l)*min(height[l], height[r]);
			if (sol<temp) sol = temp;

			if (height[l] < height[r]) l++;
			else r--;

		}

		return sol;
	}
};

int main()
{
	Solution s;
	vector<int> vec = { 2,3,4,5,18,17,6};
	s.maxArea(vec);
    return 0;
}

