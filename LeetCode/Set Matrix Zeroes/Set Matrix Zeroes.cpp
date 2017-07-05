// Set Matrix Zeroes.cpp : Defines the entry point for the console application.
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
	void setZeroes(vector<vector<int>>& matrix) {
		int rows = matrix.size();
		if (rows <= 0) return;
		int cols = matrix[0].size();
		int col0 = 1;

		for (int i = 0; i < rows; i++)
		{
			if (matrix[i][0] == 0) col0 = 0;
			for (int j = 1; j < cols; j++)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = cols - 1; j >= 1; j--) // !! j >= 0 is incorrect
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
			}
			if (col0 == 0) matrix[i][0] = 0;
		}
	}
};


void setZeroes(vector<vector<int> > &matrix) {
	int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

	for (int i = 0; i < rows; i++) {
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++)
			if (matrix[i][j] == 0)
				matrix[i][0] = matrix[0][j] = 0;
	}

	for (int i = rows - 1; i >= 0; i--) {
		for (int j = cols - 1; j >= 1; j--)
			if (matrix[i][0] == 0 || matrix[0][j] == 0)
				matrix[i][j] = 0;
		if (col0 == 0) matrix[i][0] = 0;
	}
}


int main()
{
	vector<vector<int>> v = { {1, 0} };

	Solution s;
	s.setZeroes(v);
    return 0;
}

