// Merge k Sorted Lists.cpp : Defines the entry point for the console application.
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		if (lists.size() == 0) return nullptr;

		while (lists.size() > 1)
		{
			vector<ListNode*> temp;
			for (int i = 0; i+1 < lists.size(); i+=2)
			{
				ListNode* root = merge2(lists[i], lists[i + 1]);
				temp.push_back(root);
			}

			if (lists.size() % 2 == 1)
			{
				temp.push_back(lists[lists.size()-1]);
			}

			lists = temp;
		}
		
		return lists[0];
	}

	ListNode* merge2(ListNode* l1, ListNode* l2)
	{
		ListNode dummy(0);
		ListNode* cur = &dummy;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}

		cur->next = (l1 ? l1 : l2);
		
		return dummy.next;
	}
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

int main()
{
	ListNode* r1, *r2 = nullptr;
	vector<int> v = { 1 };
	gen(&r1, v);
	vector<ListNode*> vv;
	vv.push_back(r2);
	vv.push_back(r1);
	Solution s;
	s.mergeKLists(vv);
    return 0;
}

