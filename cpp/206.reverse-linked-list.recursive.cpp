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
	ListNode* reverseList(ListNode* head) {
		ListNode *nextNode = NULL;
		ListNode *newHead = NULL;

		if (head == NULL) {
			return NULL;
		}

		nextNode = head->next;

		if (nextNode != NULL) {
			newHead = reverseList(nextNode);
			nextNode->next = head;
			head->next = NULL;
		} else {
			newHead = head;
			newHead->next = NULL;
		}

		return newHead;
	}
};
