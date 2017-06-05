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
	char c;
	Node* children[26];

	Node() { 
		c = ' ';
		memset(children, 0, sizeof(children)); }
};

class Tree
{
public:
	void Insert(string s)
	{
		if (s.length() < 1) return;
		roots[s[0] - 'a'].c = s[0];
		Node* pCur = &roots[s[0] - 'a'];

		for (int i = 1; i < s.length(); i++)
		{
			Node* node = new Node();
			node->c = s[i];
			pCur->children[s[i] - 'a'] = node;
		}
	}

	Node roots[26];
};

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		
	}

};


int main()
{
	Tree t;
	t.Insert("the");
	Solution s;
    return 0;
}

