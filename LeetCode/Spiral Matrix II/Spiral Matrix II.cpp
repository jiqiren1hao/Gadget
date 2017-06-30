// Spiral Matrix II.cpp : Defines the entry point for the console application.
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
	vector<vector<int>> generateMatrix(int n) {

		int cur = 1;
		vector<vector<int>> ret(n, vector<int>(n, 0));

		for (int i = 0; i < n / 2; i++)
		{
			int n2 = n - (i + 1);
			int j = i;
			while (j < n2) ret[i][j++] = cur++;
			
			j = i;
			while (j < n2) ret[j++][n2] = cur++;

			j = n2;
			while (j > i) ret[n2][j--] = cur++;

			j = n2;
			while (j > i) ret[j--][i] = cur++;
		}

		if (n % 2 != 0) ret[n / 2][n / 2] = cur;

		return ret;
	}
};


int main()
{
	Solution s;
	s.generateMatrix(5);
    return 0;
}

