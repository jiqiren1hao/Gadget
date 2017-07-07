// Remove Duplicates from Sorted List.cpp : Defines the entry point for the console application.
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


class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) return nullptr;
 		ListNode dummy(0);
		dummy.next = head;

		ListNode* pCur = head;
		ListNode* pPre = &dummy;

		while (pCur->next != nullptr)
		{
			if (pCur->val == pCur->next->val)
			{
				pPre->next = pCur->next;
				pCur->next = nullptr;
				pCur = pPre->next;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}

		return dummy.next;
	}
};

int main()
{
    return 0;
}

