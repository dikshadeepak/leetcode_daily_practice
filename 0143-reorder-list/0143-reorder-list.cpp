class Solution {
public:
    ListNode* left;

    void solve(ListNode* right) {

        // Reached the end
        if (right == NULL)
            return;

        // Go till the last node
        solve(right->next);

        // If left has crossed right
        // or they have met
        if (left == NULL)
            return;

        if (left == right || left->next == right) {
            right->next = NULL;
            left = NULL;
            return;
        }

        // Put right node after left
        ListNode* nextLeft = left->next;

        left->next = right;
        right->next = nextLeft;

        // Move left forward
        left = nextLeft;
    }

    void reorderList(ListNode* head) {

        left = head;

        solve(head);
    }
};