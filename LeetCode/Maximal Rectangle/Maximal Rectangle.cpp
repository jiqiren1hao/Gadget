// Maximal Rectangle.cpp : Defines the entry point for the console application.
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


class Solution1 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		rows = matrix.size();
		if (rows == 0) return 0;
		cols = matrix[0].size();
		if (cols == 0) return 0;
		int ret = 0;
		minval = -max(rows, cols);

		for (int i = 0; i < rows; i++)
		{
			for (int j = i+1; j <= rows; j++)
			{
				vector<int> v(cols, 0);
				getv(matrix, v, i, j);
				int t = sum(v);
				if (t > ret) ret = t;
			}
		}

		return ret;
	}

	int sum(vector<int>& v)
	{
		int a = v[v.size() - 1];
		vector<int> r(v.size(), a);
		
		for (int i = v.size() - 2; i >= 0; i--)
		{
			a = max(v[i], a + v[i]);
			r[i] = max(a, r[i + 1]);
		}

		return r[0];
	}

	void getv(vector<vector<char>>& matrix, vector<int>& v, int i, int j)
	{
		int val = j - i;

		for (int k = 0; k < cols; k++)
		{
			v[k] = val;
			for (int r = i; r < j; r++)
			{
				if (matrix[r][k] == '0')
				{
					v[k] = minval;
					break;
				}
			}
		}
	}

	int rows, cols;
	int minval;
};


class Solution2 {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {

		int rows = matrix.size();
		if (rows == 0) return 0;
		int cols = matrix[0].size();
		if (cols == 0) return 0;

		vector<int> h(cols+1, 0);  //!!
		int ret = 0;

		for (int i = 0; i < rows; i++)
		{
			stack<int> s;
			for (int j = 0; j < cols + 1;)
			{
				if (j < cols)
				{
					if (matrix[i][j] == '1') h[j]++;
					else h[j] = 0;
				}

				if (s.empty() || h[j] >= h[s.top()])
				{
					s.push(j++);
				}
				else
				{
					while (!s.empty() && h[j] < h[s.top()])
					{
						int t = s.top();
						s.pop();
						int len = s.empty() ? j : j - s.top() - 1;
						int size = len*h[t];
						if (size > ret) ret = size;
					}
					s.push(j++);
				}
			}
		}

		return ret;
	}
};

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int rows = matrix.size();
		if (rows == 0) return 0;
		int cols = matrix[0].size();
		if (cols == 0) return 0;

		vector<int> left(cols, 0);
		vector<int> right(cols, cols);
		vector<int> h(cols, 0);
		int ret = 0;

		for (int i = 0; i < rows; i++)
		{
			int cur_left = 0, cur_right = cols;
			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == '1') h[j]++;
				else h[j] = 0;
			}

			for (int j = 0; j < cols; j++)
			{
				if (matrix[i][j] == '1') left[j] = max(left[j], cur_left);
				else 
				{
					cur_left = j + 1;
					left[j] = 0; // don't forgot to reset here
				}
			}

			for (int j = cols - 1; j >= 0; j--)
			{
				if (matrix[i][j] == '1') right[j] = min(right[j], cur_right);
				else
				{
					cur_right = j;
					right[j] = cols;
				}
			}

			for (int j = 0; j < cols; j++)
			{
				int t = (right[j] - left[j])*h[j];
				ret = max(t, ret);
			}
		}

		return ret;
	}
};


int main()
{
	vector<vector<char>> v = { {'0','1','1','0','1'},{'1','1','0','1','0'},{'0','1','1','1','0'},{ '1','1','1','1','0' }, {'1','1','1','1','1'}, {'0','0','0','0','0'} };

	Solution s;
	s.maximalRectangle(v);
    return 0;
}

