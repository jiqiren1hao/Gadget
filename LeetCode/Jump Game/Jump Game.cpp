// Jump Game.cpp : Defines the entry point for the console application.
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
	bool canJump(vector<int>& nums) {
		int n = nums.size();

		if (n <= 1) return true;
		vector<int> r(n, 0);
		r[n - 1] = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			if (nums[i] == 0) continue;
			if (i + nums[i] >= n-1)
			{
				r[i] = 1;
				update(r, i + 1, 1);
				continue;
			}

			r[i] = r[i+nums[i]] == 0 ? 0 : 1 + r[nums[i]];
			if (r[i] != 0) update(r, i + 1, r[i]);
		}

		return r[0] > 0;
	}

	void update(vector<int>& v, int index, int value)
	{
		for (int i = index; i<v.size() && (v[i] > value || v[i] == 0); i++)
		{
			v[i] = value;
		}
	}
};


bool canJump(int A[], int n) {
	int i = 0;
	for (int reach = 0; i < n && i <= reach; ++i)
		reach = max(i + A[i], reach);
	return i == n;
}

class Solution2 {
public:
	bool canJump(vector<int>& nums) {
		int n = nums.size();
		// 最远可到的标号（可能超过size)
		int farthest = 0;
		int i;

		for (i = 0; i < n && i <= farthest; i++) {
			// 更新最远可到标号
			farthest = max(farthest, i + nums[i]);

		}

		if (i == n) {
			return true;
		}
		return false;
	}
};

int main()
{
	vector<int> v = { 5,9,3,2,1,0,2,3,3,1,0,0 };
	Solution s;
	s.canJump(v);
    return 0;
}

