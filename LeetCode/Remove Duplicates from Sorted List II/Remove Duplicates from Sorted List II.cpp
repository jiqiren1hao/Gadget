// Remove Duplicates from Sorted List II.cpp : Defines the entry point for the console application.
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
#include <set>
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;

		ListNode dummy(0);
		dummy.next = head;

		ListNode* pPre = &dummy;
		ListNode* pCur = dummy.next;
		int dup = head->val-1;

		while (pCur != nullptr)
		{
			if ((pCur->next != nullptr && pCur->val == pCur->next->val) || pCur->val == dup)
			{
				// remove pCur;
				dup = pCur->val;
				pPre->next = pCur->next;
				pCur->next = nullptr;
				pCur = pPre->next;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->next;
				if (pCur != nullptr) dup = pCur->val - 1;
			}
		}

		return dummy.next;
	}
};

int main()
{
    return 0;
}

