class Solution {
public:

    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;

            start++;
            end--;
        }
        return true;
    }

    void solve(string& s, int idx,
               vector<string>& temp,
               vector<vector<string>>& ans) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        // Try every possible partition
        for (int i = idx; i < s.size(); i++) {
            // Only take substring if it is palindrome
            if (isPalindrome(s, idx, i)) {
                // Take
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(s, i + 1, temp, ans);
                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;
        solve(s, 0, temp, ans);
        return ans;
    }
};