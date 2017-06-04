// Substring with Concatenation of All Words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <stack>
using namespace std;

struct Node
{
	string s;
	int index;
};
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		
		vector<int> v;
		slen = s.size();
		if (words.size() == 0 || slen == 0) return v;

		build(words);
		vector<bool> map(size, false);
		int first = -1;
		int found = 0;
		int start = 0;
		for (int i = 0; i <= (slen - wordslen); )
		{
			int j = 0;
			for (; j < size-found; j++)
			{
				int n = find(s.substr(i + j*wordlen, wordlen));
				if (-1 != n && !map[n])
				{
					map[n] = true;
					if (j == 0)
					{
						first = n;
					}
				}
				else
				{
					break;
				}
			}

			if (j == 0)
			{
				i++;
				start = i;
				found = 0;
				map.clear();
				map.resize(size, false);
			}
			else if (j < size)
			{
				i = i + j*wordlen;
				start = i;
				map.clear();
				map.resize(size, false);
				found = 0;
			}
			else
			{
				v.push_back(start);
				map[first] = false;
				start = i + wordlen;
				i += size*wordlen;
				found = size - 1;
			}
		}

		return v;
	}

	void build(vector<string>& words)
	{
		size = words.size();
		wordlen = words[0].length();
		wordslen = size*wordlen;
		vec.resize(size);

		for (int i = 0; i < size; i++)
		{
			unsigned int n = 0;
			for (int j = 0; j < words[i].length(); j++)
			{
				n += words[i][j];
			}
			
			vec[n%size].push_back({ words[i], i });
		}
	}

	int find(string s)
	{
		unsigned int n = 0;
		for (int j = 0; j < s.length(); j++)
		{
			n += s[j];
		}
		n = n%size;

		for (int i = 0; i < vec[n].size(); i++)
		{
			if (s == vec[n][i].s) return vec[n][i].index;
		}

		return -1;
	}

	vector<vector<Node>> vec;
	int size;
	int slen;
	int wordslen;
	int wordlen;
};


int main()
{
	string s1 = "barfoofoobarthefoobarman";
	vector<string> w = { "bar", "foo", "the" };
	Solution s;
	s.findSubstring(s1, w);
    return 0;
}

