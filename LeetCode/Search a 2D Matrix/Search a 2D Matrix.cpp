// Search a 2D Matrix.cpp : Defines the entry point for the console application.
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


// log(m*n)
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows <= 0) return false;
		int cols = matrix[0].size();

		int l = 0, r = rows*cols - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			int i = mid / cols;
			int j = mid % cols;
			if (matrix[i][j] == target) return true;
			else if (matrix[i][j] < target) l = mid + 1;
			else r = mid - 1;
		}

		return false;
	}
};


// log(m) + log(n)
class Solution2 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int rows = matrix.size();
		if (rows <= 0) return false;
		int cols = matrix[0].size();
		if (cols <= 0) return false;

		int l = 0, r = rows - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (matrix[mid][0] == target) return true;
			else if (matrix[mid][0] < target) l = mid + 1;
			else r = mid - 1;
		}

		if (r < 0) return false;
		int row = 0;
		if (l < rows && target > matrix[l][0]) row = l;
		else row = r;

		l = 0, r = cols - 1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (matrix[row][mid] == target) return true;
			else if (matrix[row][mid] < target) l = mid + 1;
			else r = mid - 1;
		}

		return false;
	}
};


class Solution3 {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int m = matrix.size();
		if (m == 0) return false;
		int n = matrix[0].size();
		if (n == 0) return false;

		int l = 0, r = m - 1, mid, row = -1;
		while (l <= r) {
			mid = l + (r - l) / 2;
			if (matrix[mid][0] < target) {
				row = mid;
				l = mid + 1;
			}
			else if (matrix[mid][0] > target)
				r = mid - 1;
			else
				return true;
		}

		if (row == -1) return false;

		l = 0;
		r = n - 1;
		while (l <= r) {
			mid = l + (r - l) / 2;
			if (matrix[row][mid] < target)
				l = mid + 1;
			else if (matrix[row][mid] > target)
				r = mid - 1;
			else
				return true;
		}

		return false;
	}
};

int main()
{
	Solution2 s;
	vector<vector<int>> v = { {1} };
	s.searchMatrix(v, 0);
    return 0;
}

