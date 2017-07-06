// Remove Duplicates from Sorted Array II.cpp : Defines the entry point for the console application.
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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0) return 0;

		int newlen = 0;
		int cnt = 0;
		int cur = nums[0] + 1;;
		for (int i = 0; i < nums.size(); i++)
		{
			if (cur == nums[i])
			{
				cnt++;
				if (cnt > 2) continue;
			}
			else
			{
				cur = nums[i];
				cnt = 1;
			}

			nums[newlen++] = nums[i];
		}

		return newlen;
	}
};


int main()
{
    return 0;
}

