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

    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {

            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverseList(l1);
        l2 = reverseList(l2);

        int carry = 0;

        ListNode* head = NULL;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int sum = carry;

            if (l1 != NULL) {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            int digit = sum % 10;

            carry = sum / 10;

            ListNode* curr = new ListNode(digit);
            curr->next = head;
            head = curr;
        }
        return head;
    }
};