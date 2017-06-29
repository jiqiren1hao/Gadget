// Merge Intervals.cpp : Defines the entry point for the console application.
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

/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:

	static bool comp(Interval& l, Interval& r)
	{
		return l.start < r.start;
	}

	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> ret;

		size_t s = intervals.size();
		if (s == 0) return ret;

		sort(intervals.begin(), intervals.end(), comp);

		Interval cur = intervals[0];
		for (int i = 1; i < s; i++)
		{
			if (intervals[i].start <= cur.end)
			{
				if (intervals[i].end <= cur.end)
				{
					continue;
				}
				else
				{
					cur.end = intervals[i].end;
					continue;
				}
			}
			else
			{
				ret.push_back(cur);
				cur = intervals[i];
				continue;
			}
		}

		ret.push_back(cur);

		return ret;
	}
};

int main()
{
    return 0;
}

