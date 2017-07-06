// Combinations.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> combine(int n, int k) {
		m_n = n;
		m_k = k;
		vector<int> v(k, 0);

		find(v, 0, 0);
		
		return ret;
	}


	void find(vector<int>& v, int index, int cur)
	{
		if (index == m_k)
		{
			ret.push_back(v);
			return;
		}

		for (int i = cur + 1; i <= m_n - (m_k - index) + 1; i++)
		{
			v[index] = i;
			find(v, index + 1, i);
		}
	}

	int m_n, m_k;
	vector<vector<int>> ret;
};


class Solution2 {
	vector<vector<int>> results;
	vector<int> result;
	void generate(int n, int k, int j)
	{
		if (k == 0)
		{
			results.push_back(result);
			return;
		}
		for (int i = j; i <= n - k + 1; ++i)
		{
			result.push_back(i);
			generate(n, k - 1, i + 1);
			result.pop_back();
		}
	}
public:
	vector<vector<int>> combine(int n, int k) {
		generate(n, k, 1);
		return results;
	}

};

int main()
{

	Solution s;
	s.combine(4, 2);
    return 0;
}

