// Largest Rectangle in Histogram.cpp : Defines the entry point for the console application.
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
	int largestRectangleArea(vector<int>& heights) {
		int s = heights.size();
		vector<int> leftfirstlower(s, -1);
		vector<int> rightfirstlower(s, s);

		for (int i = 1; i <s; i++)
		{
			int t = i - 1;
			while (t >= 0 && heights[t] >= heights[i])
			{
				t = leftfirstlower[t];
			}
			leftfirstlower[i] = t;
		}

		for (int i = s - 1; i >= 0; i--)
		{
			int t = i + 1;
			while (t < s && heights[t] >= heights[i])
			{
				t = rightfirstlower[t];
			}
			rightfirstlower[i] = t;
		}

		int ret = 0;
		for (int i = 0; i < s; i++)
		{
			int t = heights[i] * (rightfirstlower[i] - leftfirstlower[i] - 1);
			ret = max(ret, t);
		}

		return ret;
	}
};


class Solution2 {
public:
	int largestRectangleArea(vector<int>& heights) {
		int n = heights.size();
		stack<int> s;
		heights.push_back(0);
		int result = 0;
		for (int i = 0; i<n + 1;) {
			if (s.empty() || heights[s.top()] <= heights[i]) {
				s.push(i++);
			}
			else {
				int temp = s.top(); s.pop();
				int len;
				if (s.empty()) len = i;
				else len = i - s.top() - 1;
				result = max(result, heights[temp] * len);
			}
		}
		return result;
	}
};

int main()
{
	vector<int> v = { 2,4,6,3 };
	Solution2 s;
	s.largestRectangleArea(v);

	stack<int> ss;
	ss.push(1);
	ss.push(2);
	int t = ss.top();
	ss.pop();
    return 0;
}

