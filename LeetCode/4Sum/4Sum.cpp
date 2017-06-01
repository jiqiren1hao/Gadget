// 4Sum.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ret;
		if (nums.size() < 4) return ret;
		sort(nums.begin(), nums.end());

		for (int i1 = 0; i1 < nums.size();)
		{
			for (int i2 = i1 + 1; i2 < nums.size(); )
			{
				int t = target - nums[i1] - nums[i2];
				for (int l = i2 + 1, r = nums.size() - 1; l < r;)
				{
					int c = nums[l] + nums[r];
					if (c < t)
					{
						int lv = nums[l++];
						while (l + 1 < nums.size() && nums[l] == lv)l++;
						continue;
					}
					else if (c > t)
					{
						int rv = nums[r--];
						while (r - 1 >= 0 && nums[r] == rv)r--;
						continue;
					}
					else
					{
						ret.push_back({ nums[i1], nums[i2], nums[l], nums[r] });
						int lv = nums[l++];
						while (l + 1 < nums.size() && nums[l] == lv)l++;
						int rv = nums[r--];
						while (r - 1 >= 0 && nums[r] == rv)r--;
					}
				}

				int v2 = nums[i2++];
				while (i2 + 1 < nums.size() && nums[i2] == v2)i2++;
			}

			int v1 = nums[i1++];
			while (i1 + 1 < nums.size() && nums[i1] == v1)i1++;
		}

		return ret;
	}
};

class Solution2 {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		for (int i = 0, len = nums.size(); i < len - 3; i++) {
			if (i && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			for (int j = i + 1; j < len - 2; j++) {
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				int left = j + 1, right = len - 1;
				while (left < right) {
					int sum = nums[left] + nums[right] + nums[i] + nums[j];
					if (sum < target) while (++left < len && nums[left] == nums[left - 1]);
					else if (sum > target) while (--right > j && nums[right] == nums[right + 1]);
					else {
						result.push_back({ nums[i], nums[j], nums[left], nums[right] });
						while (++left < len && nums[left] == nums[left - 1]);
						while (--right > j && nums[right] == nums[right + 1]);
					}
				}
			}
		}
		return result;
	}
};

int main()
{
	Solution s;
	vector<int> v = { -1,2,2,-5,0,-1,4 };
	s.fourSum(v, 3);
    return 0;
}

