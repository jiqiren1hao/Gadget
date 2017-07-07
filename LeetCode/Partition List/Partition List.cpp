// Partition List.cpp : Defines the entry point for the console application.
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
	ListNode* partition(ListNode* head, int x) {
		if (head == nullptr) return nullptr;
		ListNode dummy(0);
		ListNode dummy1(0);
		ListNode dummy2(0);

		dummy.next = head;

		ListNode* pCur = head;
		ListNode* p1 = &dummy1;
		ListNode* p2 = &dummy2;

		while (pCur != nullptr)
		{
			dummy.next = pCur->next;
			pCur->next = nullptr;

			if (pCur->val < x)
			{
				p1->next = pCur;
				p1 = pCur;
			}
			else
			{
				p2->next = pCur;
				p2 = pCur;
			}


			pCur = dummy.next;
		}

		p1->next = dummy2.next;
		return dummy1.next;
	}
};

int main()
{
    return 0;
}

