// Length of Last Word.cpp : Defines the entry point for the console application.
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
	int lengthOfLastWord(string s) {
		size_t size = s.length();
		if (size == 0) return 0;

		int i = size - 1;
		while (i >= 0 && s[i] == ' ') i--;
		int len = 0;
		while (i >= 0 && s[i] != ' ')
		{
			i--;
			len++;
		}

		return len;
	}
};

int main()
{
    return 0;
}

