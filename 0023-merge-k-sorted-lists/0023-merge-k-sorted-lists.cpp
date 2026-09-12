/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0)
            return NULL;

        ListNode* ans = lists[0];

        for (int i = 1; i < lists.size(); i++) {

            ListNode* l1 = ans;
            ListNode* l2 = lists[i];

            ListNode* dummy = new ListNode(0);
            ListNode* curr = dummy;

            while (l1 != NULL && l2 != NULL) {

                if (l1->val <= l2->val) {
                    curr->next = l1;
                    l1 = l1->next;
                }
                else {
                    curr->next = l2;
                    l2 = l2->next;
                }

                curr = curr->next;
            }

            if (l1 != NULL)
                curr->next = l1;

            if (l2 != NULL)
                curr->next = l2;

            ans = dummy->next;
        }

        return ans;
    }
};