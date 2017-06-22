// Group Anagrams.cpp : Defines the entry point for the console application.
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

// badly description!!!
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, multiset<string>> mp;
		for (string s : strs) {
			string t = s;
			sort(t.begin(), t.end());
			mp[t].insert(s);
		}
		vector<vector<string>> anagrams;
		for (auto m : mp) {
			vector<string> anagram(m.second.begin(), m.second.end());
			anagrams.push_back(anagram);
		}
		return anagrams;
	}
};


int main()
{
    return 0;
}

