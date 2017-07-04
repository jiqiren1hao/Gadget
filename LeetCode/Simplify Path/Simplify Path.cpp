// Simplify Path.cpp : Defines the entry point for the console application.
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
	string simplifyPath(string path) {
		vector<string> paths;
		int start = 0;

		for (int i = 0; i < path.length();)
		{
			while (i + 1 < path.length() && path[i + 1] == '/') i++;
			start = i++;

			if (i == path.length()) break;

			while (i < path.length() && path[i] != '/') i++;			
			string s = path.substr(start + 1, i - start-1);

			if (s == ".") continue;
			else if (s == "..")
			{
				if (paths.empty()) continue;
				else paths.pop_back();
			}
			else
			{
				paths.push_back(s);
			}
		}

		if (paths.empty()) return "/";
		else
		{
			string s;
			for (int i = 0; i < paths.size(); i++)
			{
				s.push_back('/');
				s.append(paths[i]);
			}

			return s;
		}
	}
};

string simplifyPath(string path) {
	vector<string>   nameVect;
	string name;

	path.push_back('/');
	for (int i = 0; i<path.size(); i++) {
		if (path[i] == '/') {
			if (name.size() == 0)continue;
			if (name == "..") {		//special case 1：double dot，pop dir
				if (nameVect.size()>0)nameVect.pop_back();
			}
			else if (name == ".") {//special case 2:singel dot，don`t push
			}
			else {
				nameVect.push_back(name);
			}
			name.clear();
		}
		else {
			name.push_back(path[i]);//record the name
		}
	}

	string result;
	if (nameVect.empty())return "/";
	for (int i = 0; i<nameVect.size(); i++) {
		result.append("/" + nameVect[i]);
	}
	return result;
}

int main()
{
	string v = "/a/b/.///../../c/";
	Solution s;
	s.simplifyPath(v);
    return 0;
}

