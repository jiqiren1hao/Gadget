// Minimum Window Substring.cpp : Defines the entry point for the console application.
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
	string minWindow(string s, string t) {
		if (s.length() < t.length()) return "";
		unordered_map<char, int> mp;

		int tsize = t.length();
		int rets=0, retlen=INT_MAX;
		int curs=0, cure = 0;
		for (int i = 0; i < tsize; i++)
		{
			mp[t[i]]++;
		}

		bool moveEnd = true;
		while (!moveEnd || cure < s.length())
		{
			if (moveEnd)
			{
				if (mp.find(s[cure]) != mp.end())
				{
					// find
					mp[s[cure]]--;
					if (mp[s[cure]] >= 0) tsize--;

					if (tsize == 0)
					{
						moveEnd = false;
						if (cure - curs + 1 < retlen)
						{
							rets = curs;
							retlen = cure - curs + 1;
						}

						continue;
					}
				}

				cure++;
			}
			else
			{
				if (curs > cure) break;
				if (mp.find(s[curs]) != mp.end())
				{
					mp[s[curs]]++;
					if (mp[s[curs]] > 0)
					{
						tsize++;
						moveEnd = true;
						cure++;
						curs++;
						continue;
					}
				}

				if (cure - curs < retlen)
				{
					rets = curs+1;
					retlen = cure - curs;
				}

				curs++;
			}
		}

		if (retlen == INT_MAX) return "";
		return s.substr(rets, retlen);
	}
};

class Solution2 {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t) map[c]++;

		int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;

		while (end<s.size()) {
			if (map[s[end]]>0) counter--;
			map[s[end]]--;
			end++;
			while (counter == 0) {
				if (end - begin<d) { head = begin; d = end - head; }
				if (map[s[begin]] == 0) counter++;
				map[s[begin]]++; begin++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};


int main()
{
	string s = "bdab";
	string t = "ab";
	Solution s1;
	s1.minWindow(s, t);
    return 0;
}

