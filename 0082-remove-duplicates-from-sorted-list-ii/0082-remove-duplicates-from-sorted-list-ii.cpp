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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == NULL || head->next == NULL)
            return head;

        ListNode* h1 = new ListNode(0);
        h1->next = head;

        ListNode* curr = h1;

        while (curr->next != NULL && curr->next->next != NULL) {

            if (curr->next->val == curr->next->next->val) {

                int duplicate = curr->next->val;

                while (curr->next != NULL &&
                       curr->next->val == duplicate) {

                    curr->next = curr->next->next;
                }
            }
            else {
                curr = curr->next;
            }
        }

        head = h1->next;

        return head;
    }
};