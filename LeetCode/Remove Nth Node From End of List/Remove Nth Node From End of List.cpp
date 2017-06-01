// Remove Nth Node From End of List.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

struct ListNode{
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		int cache = n + 1;
		ListNode* pCur = head;
		ListNode* pCache = pCur;
		while (pCur)
		{
			if (cache <= 0) pCache = pCache->next;
			pCur = pCur->next;
			cache--;
		}

		if (cache == 1)
		{
			head = pCache->next;
			delete pCache;
		}
		else
		{
			ListNode* pDel = pCache->next;
			pCache->next = pDel->next;
			delete pDel;
		}

		return head;
	}
};

int main()
{
	ListNode* root = nullptr;
	Solution s;
	gen(&root, { 1,2 });
	s.removeNthFromEnd(root, 1);
    return 0;
}

