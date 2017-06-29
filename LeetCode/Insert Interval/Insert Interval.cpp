// Insert Interval.cpp : Defines the entry point for the console application.
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
	vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ret;
		size_t s = intervals.size();

		Interval cur;
		int i = 0;
		bool finished = false;

		for (; i < s; i++)
		{
			if (newInterval.start > intervals[i].end)
			{
				ret.push_back(intervals[i]);
				continue;
			}
			else if (newInterval.start >= intervals[i].start)
			{
				if (newInterval.end <= intervals[i].end)
				{
					while (i < s) ret.push_back(intervals[i++]);
					finished = true;
					break;
				}
				else
				{
					newInterval.start = min(newInterval.start, intervals[i].start);
					newInterval.end = max(newInterval.end, intervals[i].end);
				}
			}
			else
			{
				if (newInterval.end < intervals[i].start)
				{
					ret.push_back(newInterval);
					while (i < s) ret.push_back(intervals[i++]);
					finished = true;
					break;
				}
				else
				{
					newInterval.start = min(newInterval.start, intervals[i].start);
					newInterval.end = max(newInterval.end, intervals[i].end);
				}
			}
		}

		if (!finished) ret.push_back(newInterval);

		return ret;
	}
};

int main()
{
    return 0;
}

