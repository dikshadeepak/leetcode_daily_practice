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
    vector<int> nextLargerNodes(ListNode* head) {

        vector<int> ans;
        stack<pair<int, int>> st;

        ListNode* curr = head;
        int index = 0;

        while (curr != NULL) {

            while (!st.empty() && st.top().first < curr->val) {

                ans[st.top().second] = curr->val;
                st.pop();
            }
            ans.push_back(0);
            st.push({curr->val, index});

            index++;
            curr = curr->next;
        }

        return ans;
    }
};