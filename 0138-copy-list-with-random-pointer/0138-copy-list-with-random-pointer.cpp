/*
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        Node* curr = head;

        while (curr != NULL) {

            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next = copy;

            curr = copy->next;
        }

        curr = head;

        while (curr != NULL) {

            Node* copy = curr->next;

            if (curr->random != NULL)
                copy->random = curr->random->next;

            curr = copy->next;
        }
        curr = head;

        Node* newHead = head->next;

        while (curr != NULL) {

            Node* copy = curr->next;

            curr->next = copy->next;

            if (copy->next != NULL)
                copy->next = copy->next->next;

            curr = curr->next;
        }

        return newHead;
    }
};