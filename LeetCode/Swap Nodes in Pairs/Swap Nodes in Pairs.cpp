// Swap Nodes in Pairs.cpp : Defines the entry point for the console application.
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

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


void gen(ListNode** head, vector<int> v)
{
	*head = new ListNode(v[0]);
	ListNode* pCur = *head;

	for (int i = 1; i < v.size(); i++)
	{
		ListNode* p = new ListNode(v[i]);
		pCur->next = p;
		pCur = p;
	}
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode dummy(0);
		dummy.next = head;
		ListNode* p0 = &dummy;
		ListNode* p1 = head;
		ListNode* p2 = p1->next;

		while (p1 && p2)
		{
			p1->next = p2->next;
			p0->next = p2;
			p2->next = p1;

			p0 = p1;
			p1 = p1->next;
			if (p1 == nullptr) break;
			p2 = p1->next;
		}

		return dummy.next;

	}
};

int main()
{
	vector<int> v = { 1,2,3,4,5 };
	ListNode* r;
	gen(&r, v);
	Solution s;
	s.swapPairs(r);
    return 0;
}

