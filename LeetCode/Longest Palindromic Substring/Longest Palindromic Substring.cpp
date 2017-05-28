// Longest Palindromic Substring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		int n = s.size();
		if (s.size() == 1) return s;
		int nMax = 1;
		int nBegin=0, nEnd2=0;
		
		for (int i = 1; i < n; i++)
		{
			int nStart = i-1;
			int nEnd = i;

			int n = GetMax(nStart, nEnd, s);
			if (nMax < n)
			{
				nBegin = nStart;
				nEnd2 = nEnd;
				nMax = n;
			}

			nStart = i - 1;
			nEnd = i + 1;
			n = GetMax(nStart, nEnd, s);
			if (nMax < n)
			{
				nBegin = nStart;
				nEnd2 = nEnd;
				nMax = n;
			}
		}

		return s.substr(nBegin, nEnd2 - nBegin + 1);
	}

	int GetMax(int& n1, int& n2, string& s)
	{
		int a = n1, b = n2;
		for (int i = 0; (a >= 0 && b < s.length()); i++)
		{
			if (s[a] == s[b])
			{
				a--;
				b++;
			}
			else
			{
				break;
			}
		}

		n1 = a + 1;
		n2 = b - 1;
		return n2 - n1 + 1;
	}
};

class Solution2 {
public:
	string longestPalindrome(string s) {
		int max = 0, start = 0;
		if (s.size() < 1) return s;
		for (int i = 0; i < s.size();)
		{
			int head = i, tail = i;
			while (tail < s.size() - 1 && s[tail + 1] == s[tail]) ++tail;
			i = tail + 1;
			while (head > 0 && tail < s.size() - 1 && s[head - 1] == s[tail + 1]) { head--; tail++; }
			int size = tail - head + 1;
			if (size > max)
			{
				max = size;
				start = head;
			}
		}
		return s.substr(start, max);
	}
};

class Solution3 {
public:
	string longestPalindrome(string s) {
		int n = s.length();
		int nStart = 0, nLen = 0;
		for (int i = 0; i < n;)
		{
			int head = i, rear = i;

			while (rear < n && s[rear] == s[rear + 1]) rear++;
			i = rear + 1;
			while (head > 0 && rear < n - 1 && s[head - 1] == s[rear + 1])
			{
				head--;
				rear++;
			}

			int size = rear - head + 1;
			if (size > nLen)
			{
				nStart = head;
				nLen = size;
			}
		}

		return s.substr(nStart, nLen);
	}
};

int main()
{
	string ss = "aba";
	int n = ss.length();
	Solution3 s;
	s.longestPalindrome(ss);

    return 0;
}

