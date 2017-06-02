// Reverse Nodes in k-Group.cpp : Defines the entry point for the console application.
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode dummy(0);
		ListNode* r = &dummy;
		ListNode* begin = head;
		ListNode* end = nullptr;
		ListNode* pCur = head;

		while (pCur)
		{
			int n = k;
			begin = pCur;
			while (pCur && n)
			{
				pCur = pCur->next;
				end = pCur;
				n--;
			}

			if (n == 0)
			{
				r->next = Reverse(begin, k);
				r = begin;
			}
			else
			{
				r->next = begin;
				break;
			}
		}

		return dummy.next;
	}

	ListNode* Reverse(ListNode* head, int n)
	{
		ListNode dummy(0);
		ListNode* next = head;

		while (head && n)
		{
			next = head->next;
			head->next = dummy.next;
			dummy.next = head;
			head = next;
			n--;
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
	s.reverseKGroup(r, 2);
    return 0;
}

