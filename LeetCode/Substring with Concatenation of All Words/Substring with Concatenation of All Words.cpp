// Substring with Concatenation of All Words.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int>  ret;
		if (words.size() == 0) return ret;
		if ((s.length() < (words[0].length()*words.size()))) return ret;
		unordered_map<string, int> mp;
		for(string word : words)
		{
			mp[word]++;
		}

		for (int i = 0; i <= (s.length() - (words[0].length()*words.size())); i++)
		{
			unordered_map<string, int> temp = mp;
			int j = 0;
			for (; j < words.size(); j++)
			{
				string t = s.substr(i + j*words[0].length(), words[0].length());
				if (temp.find(t) != temp.end() && temp[t] > 0)
				{
					temp[t]--;
				}
				else
				{
					break;
				}
			}

			if (j == words.size())
			{
				ret.push_back(i);
			}
		}

		return ret;
	}
};

class Solution2 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> counts;
		for (string word : words)
			counts[word]++;
		int n = s.length(), num = words.size(), len = words[0].length();
		vector<int> indexes;
		for (int i = 0; i < n - num * len + 1; i++) {
			unordered_map<string, int> seen;
			int j = 0;
			for (; j < num; j++) {
				string word = s.substr(i + j * len, len);
				if (counts.find(word) != counts.end()) {
					seen[word]++;
					if (seen[word] > counts[word])
						break;
				}
				else break;
			}
			if (j == num) indexes.push_back(i);
		}
		return indexes;
	}
};

class Solution3 {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> ret;
		int length = words[0].size();
		unordered_map<string, int> mymap;
		for (int i = 0; i < words.size(); ++i)
		{
			if (mymap.find(words[i]) == mymap.end())
				mymap[words[i]] = 1;
			else
				mymap[words[i]]++;
		}

		for (int i = 0; i < length; ++i)
		{
			int count = 0, index = i;
			while (index < s.size())
			{
				if (s.size() - index < (words.size() - count) * length)
					break;
				string temp = s.substr(index, length);
				if (mymap.find(temp) == mymap.end())
				{
					for (int j = index - length * count; j < index; j += length)
						mymap[s.substr(j, length)]++;
					count = 0;
				}
				else
				{
					if (mymap[temp] > 0)
					{
						mymap[temp]--;
						count++;
						if (count == words.size())
						{
							ret.push_back(index - length * (words.size() - 1));
							string first = s.substr(index - length * (words.size() - 1), length);
							mymap[first]++;
							count--;
						}
					}
					else
					{
						int top = index - count * length;
						while (s.substr(top, length) != temp)
						{
							count--;
							mymap[s.substr(top, length)]++;
							top += length;
						}
					}
				}
				index += length;
			}
			for (int j = index - length * count; j < index; j += length)
				mymap[s.substr(j, length)]++;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<string> v = { "a", "a" };
	s.findSubstring("a", v);

    return 0;
}