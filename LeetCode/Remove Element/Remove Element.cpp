// Remove Element.cpp : Defines the entry point for the console application.
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
	int removeElement(vector<int>& nums, int val) {

		int newLen = 0;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == val)continue;
			else
			{
				nums[newLen++] = nums[i];
			}
		}

		return newLen;
	}
};

int main()
{
	vector<int> v = { 1,2,2,3,2 };
	Solution s;
	s.removeElement(v, 2);
    return 0;
}

