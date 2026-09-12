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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right)
            return head;

        ListNode* h1 = new ListNode(0);
        h1->next = head;

        ListNode* curr = h1;

        for (int i = 1; i < left; i++) {
            curr = curr->next;
        }

        ListNode* prev = NULL;
        ListNode* temp = curr->next;

        for (int i = 0; i <= right - left; i++) {

            ListNode* next = temp->next;

            temp->next = prev;
            prev = temp;
            temp = next;
        }


        curr->next->next = temp;
        curr->next = prev;

        return h1->next;
    }
};