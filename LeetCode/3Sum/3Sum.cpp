// 3Sum.cpp : Defines the entry point for the console application.
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
	bool find(vector<int>& v, int target, int index, vector<int>& a, vector<int>& b)
	{
		for (int i = 0, j = v.size() - 1; i < j;)
		{
			if (v[i] + v[j] < target) i++;
			else if (v[i] + v[j] > target) j--;
			else
			{
				// v[i] + v[j] == target
				if (i == index)
				{
					i++;
					continue;
				}
				else if (j == index)
				{
					j--;
					continue;
				}

				int t = max(v[i], v[j]);
				if (v[index] > 0 && t > 0 && t < v[index])
				{
					i++;
					j--;
					continue;
				}
				a.push_back(i);
				b.push_back(j);
				int tt = v[i];
				while (i < v.size() && tt == v[i]) i++;
				j--;
			}
		}

		return a.size() > 0;
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ret;

		sort(nums.begin(), nums.end());
		int index0 = 0, len0 = 0;
		int pos = -1;

		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				if (len0 == 0)
				{
					index0 = i;
					len0++;
				}
				else
				{
					len0++;
				}
			}

			if (nums[i] > 0 && pos == -1)
			{
				// no zero
				pos = i;
			}
		}

		if (len0 >= 3) ret.push_back({ 0,0,0 });

		for (int i = pos; i < nums.size();)
		{
			int c = nums[i];
			vector<int> a, b;
			if (find(nums, -c, i, a, b))
			{
				for (int m = 0;m<a.size();m++)
				ret.push_back({ nums[i], nums[a[m]], nums[b[m]] });
			}

			while (i < nums.size() && c == nums[i]) i++;
		}

		return ret;
	}
};


class Solution2 {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;

		if (nums.size()<3) return ans;

		sort(nums.begin(), nums.end());

		int idx(-1);
		for (int i = 0; i<nums.size(); i++)
			if (nums[i] >= 0) {
				idx = i;
				break;
			}
		if (idx == -1) return ans;

		for (int i = 0; i <= idx; i++) {
			int target = -nums[i];
			for (int j = i + 1, k = nums.size() - 1; j<k; ) {
				if (nums[j] + nums[k] == target) {
					ans.push_back({ nums[i], nums[j], nums[k] });
					while (j<k && nums[j] == nums[j + 1]) j++;
					while (j<k && nums[k] == nums[k - 1]) k--;
					j++, k--;
				}
				else if (nums[j] + nums[k] < target)
					j++;
				else
					k--;
			}
			while (i<idx - 1 && nums[i] == nums[i + 1]) i++;
		}
		return ans;
	}
};
/*
Input:
[-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6]
Output:
[[1,-4,3],[2,-4,2],[2,-2,0],[3,-4,1],[4,-4,0],[4,-2,-2],[6,-4,-2]]
Expected:
[[-4,-2,6],[-4,0,4],[-4,1,3],[-4,2,2],[-2,-2,4],[-2,0,2]]
*/
int main()
{
	Solution s;
	vector<int> v = { -4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0 };
	s.threeSum(v);
    return 0;
}

