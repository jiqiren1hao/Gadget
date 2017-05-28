// Add Two Number.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr && l2 == nullptr) return nullptr;
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		ListNode* pLeft = l1;
		ListNode* pRight = l2;
		int nCarry = 0;
		ListNode* pCur = new ListNode(0);
		ListNode* root = pCur;
		ListNode* pPre = nullptr;

		while (pLeft != nullptr || pRight != nullptr)
		{
			int nLeft = 0;
			int nRight = 0;
			if (!pCur) pCur = new ListNode(0);
			if (pLeft != nullptr)
			{
				nLeft = pLeft->val;
			}

			if (pRight != nullptr)
			{
				nRight = pRight->val;
			}

			pCur->val = nLeft + nRight + nCarry;
			nCarry = 0;
			if (pCur->val >= 10)
			{
				pCur->val -= 10;
				nCarry = 1;
			}

			if (pLeft) pLeft = pLeft->next;
			if (pRight) pRight = pRight->next;
			if (pPre) pPre->next = pCur;
			pPre = pCur;
			pCur = pCur->next;
		}

		if (nCarry != 0)
		{
			pCur = new ListNode(0);
			pCur->val = nCarry;
			nCarry = 0;
			if (pPre) pPre->next = pCur;
		}

		return root;
	}

};

ListNode* GetList(int* nVals, int nCnt)
{
	ListNode* pCur = new ListNode(0);
	ListNode* root = pCur;
	ListNode* pPre = nullptr;
	for (int i = 0; i < nCnt; i++)
	{
		if (!pCur) pCur = new ListNode(nVals[i]);
		else pCur->val = nVals[i];
		if (pPre) pPre->next = pCur;
		pPre = pCur;
		pCur = pCur->next;

	}

	return root;
}

int main()
{
	int v1[] = { 5 };
	int v2[] = { 5 };
	ListNode* l1 = GetList(v1, 1);
	ListNode* l2 = GetList(v2, 1);
	Solution s;
	ListNode* l3 = s.addTwoNumbers(l1, l2);
    return 0;
}

