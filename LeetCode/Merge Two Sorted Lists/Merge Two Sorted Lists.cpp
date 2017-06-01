// Merge Two Sorted Lists.cpp : Defines the entry point for the console application.
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


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2;
		ListNode *root = nullptr;
		ListNode* pCur = nullptr;

		while (p1 != nullptr && p2 != nullptr)
		{
			if (p1->val <= p2->val)
			{
				if (pCur == nullptr)
				{
					pCur = p1;
					root = pCur;
				}
				else
				{
					pCur->next = p1;
					pCur = p1;
				}
				
				p1 = p1->next;
			}
			else
			{
				if (root == nullptr)
				{
					pCur = p2;
					root = pCur;
				}
				else
				{
					pCur->next = p2;
					pCur = p2;
				}

				p2 = p2->next;
			}
		}

		while (p1 != nullptr)
		{
			if (pCur == nullptr)
			{
				pCur = p1;
				root = pCur;
			}
			else
			{
				pCur->next = p1;
				pCur = p1;
			}
			
			p1 = p1->next;
		}

		while (p2 != nullptr)
		{
			if (pCur == nullptr)
			{
				pCur = p2;
				root = pCur;
			}
			else
			{
				pCur->next = p2;
				pCur = p2;
			}

			p2 = p2->next;
		}

		return root;
	}
};

class Solution2 {
public:
	// 循环迭代
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode start(0);
		ListNode *newHead = &start;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				newHead->next = l1;
				l1 = l1->next;
			}
			else
			{
				newHead->next = l2;
				l2 = l2->next;
			}
			newHead = newHead->next;
		}
		newHead->next = l1 ? l1 : l2;
		return start.next;
	}
};

int main()
{
	ListNode* r1, *r2;
	gen(&r1, { 1,3,7 });
	gen(&r2, { 2,4,5 });
	Solution s;
	s.mergeTwoLists(r1, r2);
    return 0;
}

