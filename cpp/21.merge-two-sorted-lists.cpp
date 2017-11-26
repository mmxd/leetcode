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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummyNode(0);
        ListNode *ptr = &dummyNode;
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL && p2 != NULL) {
                if (p1->val <= p2->val) {
                    ptr->next = p1;
                    p1 = p1->next;
                } else {
                    ptr->next = p2;
                    p2 = p2->next;
                }
            } else if (p1 != NULL) {
                ptr->next = p1;
                p1 = p1->next;
            } else {
                ptr->next = p2;
                p2 = p2->next;
            }

            ptr = ptr->next;
        }

        return dummyNode.next;
    }
};
