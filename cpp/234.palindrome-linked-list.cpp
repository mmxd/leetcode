/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *next = NULL;

        while (head != NULL) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        ListNode *p1 = NULL;
        ListNode *p2 = NULL;

        if (head == NULL) {
            return true;
        }

        p1 = head;
        p2 = head;
        while (p2 != NULL && p2->next != NULL && p2->next->next != NULL) {
            p1 = p1->next;
            p2 = p2->next->next;
        }


        p2 = reverseList(p1->next);
        p1->next = NULL;
        p1 = head;

        while (p1 != NULL && p2 != NULL) {
            if (p1->val != p2->val) {
                return false;
            }
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};
