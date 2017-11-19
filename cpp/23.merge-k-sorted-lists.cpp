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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummyNode(0);
        ListNode *ptr = NULL;
        ListNode *tail = &dummyNode;

        auto comp = [](ListNode *a, ListNode *b) {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> q(comp);

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] == NULL) {
                continue;
            }
            q.push(lists[i]);
        }

        while (!q.empty()) {
            ptr = q.top();
            q.pop();

            tail->next = ptr;
            ptr = ptr->next;
            tail = tail->next;

            if (ptr != NULL) {
                q.push(ptr);
            }
        }

        return dummyNode.next;
    }
};
