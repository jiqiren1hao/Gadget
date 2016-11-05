// TwoSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> sortVec = numbers;
		sort(sortVec.begin(), sortVec.end());

		int nSmall = 0;
		int nLarge = sortVec.size() - 1;

		for (; nSmall < nLarge;)
		{
			if (sortVec[nSmall] + sortVec[nLarge] == target)
			{
				// Find it!
				GetIndex(sortVec[nSmall], sortVec[nLarge], numbers);
				vector<int> ret;
				ret.push_back(sortVec[nSmall]);
				ret.push_back(sortVec[nLarge]);
				return ret;
			}
			else if (sortVec[nSmall] + sortVec[nLarge] < target)
			{
				nSmall++;
			}
			else
			{
				nLarge--;
			}
		}

	}

	void GetIndex(int& i, int& j, vector<int> &numbers)
	{
		int ii = i;
		int jj = j;
		i = 0;
		j = 0;
		for (size_t k = 0; k < numbers.size(); k++)
		{
			if (i != 0 && j != 0)
			{
				break;
			}
			if (numbers[k] == ii)
			{
				if (i == 0)
				{
					i = k + 1;
				}
				else
				{
					j = k + 1;
				}

			}
			else if (numbers[k] == jj)
			{
				if (i == 0)
				{
					i = k + 1;
				}
				else
				{
					j = k + 1;
				}
			}
		}
	}

};

int main()
{
	Solution s;
	vector<int> p = { 2, 11, 7, 15 };
	int target = 9;
	vector<int> ret = s.twoSum(p, target);

    return 0;
}

