// Combination Sum.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
		
		for (int i = start; i < v.size(); i++)
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
				if (find(v, i, t, v2))
				{
					ret = true;
					for (int j = 0; j < v2.size(); j++)
					{
						v2[j].push_back(v[i]);
						r.push_back(v2[j]);
					}
				}
			}
		}

		return ret;
	}
};

class Solution2 {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ret;
		vector<int> tempret;
		backtrack(ret, tempret, candidates, 0, target);
		return ret;
	}

	void backtrack(vector<vector<int>>& ret, vector<int>& tempret, vector<int>& cands, int sid, int remain) {
		if (remain < 0) return;
		else if (remain == 0) {
			ret.push_back(tempret);
			return;
		}
		else for (int i = sid; i<cands.size(); i++) {
			tempret.push_back(cands[i]);
			backtrack(ret, tempret, cands, i, remain - cands[i]);
			tempret.pop_back();
		}
	}
};

int main()
{
	vector<int> v = {2,3,6,7};
	Solution s;
	s.combinationSum(v, 7);
    return 0;
}

