// Text Justification.cpp : Defines the entry point for the console application.
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
	vector<string> fullJustify(vector<string>& words, int maxWidth) {

		vector<string> ret;
		int wcnt=0;
		int len=0;
		int wordsLen = 0;
		int start=0;

		for (int i = 0; i < words.size(); i++)
		{
			int sp = wcnt == 0 ? 0 : 1;
			int occupy = len + sp;
			int remain = maxWidth - occupy;

			if (remain >= 0 && remain >= words[i].length())
			{
				// OK to put another word
				wcnt++;
				len += sp + words[i].length();
				wordsLen += words[i].length();
			}
			else
			{
				// can't fix another word, current word is i th
				if (wcnt == 1)
				{
					string s = words[start];
					s.resize(maxWidth, ' ');
					ret.push_back(s);
				}
				else
				{
					int averGap = (maxWidth - wordsLen) / (wcnt - 1);
					int extra = (maxWidth - wordsLen) % (wcnt - 1);

					string s = words[start];
					for (int j = start+1; j < i; j++)
					{
						int newLen = (j - start <= extra ? 1 : 0) + averGap + s.length();
						s.resize(newLen, ' ');
						s.append(words[j]);
					}

					ret.push_back(s);
				}

				start = i;
				wcnt = 1;
				len = words[i].length();
				wordsLen = len;
			}
		}

		if (wcnt != 0)
		{
			string s = words[start];
			for (int j = start + 1; j < words.size(); j++)
			{
				s.push_back(' ');
				s.append(words[j]);
			}

			s.resize(maxWidth, ' ');
			ret.push_back(s);
		}

		return ret;
	}
};


/*
For each line, I first figure out which words can fit in. 
According to the code, these words are words[i] through words[i+k-1]. 
Then spaces are added between the words. 
The trick here is to use mod operation to manage the spaces that can't be evenly distrubuted: 
the first (L-l) % (k-1) gaps acquire an additional space.
*/
vector<string> fullJustify(vector<string> &words, int L) {
	vector<string> res;
	for (int i = 0, k, l; i < words.size(); i += k) {
		for (k = l = 0; i + k < words.size() && l + words[i + k].size() <= L - k; k++) {
			l += words[i + k].size();
		}
		string tmp = words[i];
		for (int j = 0; j < k - 1; j++) {
			if (i + k >= words.size()) tmp += " ";
			else tmp += string((L - l) / (k - 1) + (j < (L - l) % (k - 1)), ' ');
			tmp += words[i + j + 1];
		}
		tmp += string(L - tmp.size(), ' ');
		res.push_back(tmp);
	}
	return res;
}


int main()
{
	vector<string> v = { "a", "b", "c", "d", "e" };

	Solution s;
	s.fullJustify(v, 1);
    return 0;
}

