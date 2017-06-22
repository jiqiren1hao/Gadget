// Maximum Subarray.cpp : Defines the entry point for the console application.
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
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();

		if (size == 0) return 0;
		if (size == 1) return nums[0];
		int sum2 = nums[size - 1];
		int sum = sum2;

		for (int i = size - 2; i >= 0; i--)
		{
			sum2 = max(nums[i], nums[i] + sum2);
			sum = max(sum, sum2);
		}

		return sum;
	}
};

int main()
{
    return 0;
}

