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
        int val = 0;
        int carry = 0;
        ListNode dummyNode(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *ptr = &dummyNode;

        while (p1 != NULL || p2 != NULL || carry != 0) {
            val = 0;
            if (p1 != NULL) {
                val += p1->val;
                p1 = p1->next;
            }
            if (p2 != NULL) {
                val += p2->val;
                p2 = p2->next;
            }
            if (carry != 0) {
                val += carry;
            }

            carry = val / 10;
            val = val % 10;

            ptr->next = new ListNode(val);
            ptr = ptr->next;
        }

        return dummyNode.next;
    }
};
