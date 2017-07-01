// Rotate List.cpp : Defines the entry point for the console application.
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

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k <= 0) return head;
		if (head == nullptr) return nullptr;

		int k2 = k;
		ListNode dummy(0);
		int Len = 0;
		dummy.next = head;
		ListNode* pNewEnd = &dummy;
		ListNode* pCur = &dummy;

		while (pCur->next != nullptr && k > 0)
		{
			pCur = pCur->next;
			Len++;
			k--;
		}

		if (k == 0 && pCur->next == nullptr)
		{
			return head;
		}

		int n = 0;
		if (k>0)
		{
			n = Len - (k2%Len);
			while (n)
			{
				pNewEnd = pNewEnd->next;
				n--;
			}
		}
		else
		{
			while (pCur->next != nullptr)
			{
				pCur = pCur->next;
				pNewEnd = pNewEnd->next;
			}
		}



		pCur->next = dummy.next;
		dummy.next = pNewEnd->next;
		pNewEnd->next = nullptr;

		return dummy.next;
	}
};

class Solution2 {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode* slow = dummy;
		ListNode* fast = dummy;

		int count = 0;
		for (ListNode* p = head; p != NULL; p = p->next) {
			count++;
		}
		if (count == 0) {
			return head;
		}
		k %= count;
		for (int i = 0; i<k&&fast != NULL; i++) {
			fast = fast->next;
		}
		while (fast != NULL&&fast->next != NULL) {
			fast = fast->next;
			slow = slow->next;
		}
		if (slow != dummy) {
			fast->next = head;
			head = slow->next;
			slow->next = NULL;
		}

		delete dummy;
		return head;
	}
};

int main()
{
    return 0;
}

