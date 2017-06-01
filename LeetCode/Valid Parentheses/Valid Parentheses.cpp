// Valid Parentheses.cpp : Defines the entry point for the console application.
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

class Solution {
public:
	bool isValid(string s) {
		int size = s.length();
		if (size == 0) return true;

		vector<int> stack;

		for (int i = 0; i < size; i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
			{
				stack.push_back(s[i]);
			}
			else
			{
				if (stack.size()>=1 && 
					((s[i] == ')' && stack[stack.size() - 1] == '(') ||
					(s[i] == ']' && stack[stack.size() - 1] == '[') ||
					(s[i] == '}' && stack[stack.size() - 1] == '{')))
				{
					stack.pop_back();
				}
				else
				{
					return false;
				}
			}
		}

		return stack.size() == 0;
	}
};

class Solution2 {
public:
	bool isValid(string s) {
		stack<char> items;
		for (auto& c : s) {
			switch (c)
			{
			case '(':
			case '[':
			case '{':
				items.push(c); break;
			case ')':
				if (items.empty() || items.top() != '(')return false;
				else items.pop(); break;
			case ']':
				if (items.empty() || items.top() != '[')return false;
				else items.pop(); break;
			case '}':
				if (items.empty() || items.top() != '{')return false;
				else items.pop(); break;
			default:
				break;
			}
		}
		return items.empty();
	}
};

int main()
{

    return 0;
}

