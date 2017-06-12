// Combination Sum II.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> r;
		if (candidates.size() == 0) return r;

		sort(candidates.begin(), candidates.end());

		find(candidates, 0, target, r);

		return r;
	}

	bool find(vector<int>& v, int start, int target, vector<vector<int>>& r)
	{
		if (start >= v.size()) return false;
		bool ret = false;

		for (int i = start; i < v.size();)
		{
			if (v[i] > target) return ret;
			else if (v[i] == target)
			{
				r.push_back({ v[i] });
				return true;
			}
			else
			{
				vector<vector<int>> v2;
				int t = target - v[i];
				if (find(v, i+1, t, v2))
				{
					ret = true;
					for (int j = 0; j < v2.size(); j++)
					{
						v2[j].push_back(v[i]);
						r.push_back(v2[j]);
					}
				}
			}

			int c = v[i];
			while (i < v.size() && v[i] == c)i++;
		}

		return ret;
	}
};

int main()
{
	vector<int> v = { 10, 1, 2, 7, 6, 1, 5 };
	Solution s;
	s.combinationSum2(v, 8);
	return 0;
}

