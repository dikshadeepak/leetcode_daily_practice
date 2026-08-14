class Solution {
public:

    void solve(string& s, int idx,
               vector<string>& ans) {

        // Base case
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }

        // If digit, only one choice
        if (isdigit(s[idx])) {

            solve(s, idx + 1, ans);

            return;
        }

        // PICK lowercase
        s[idx] = tolower(s[idx]);

        solve(s, idx + 1, ans);

        // PICK uppercase
        s[idx] = toupper(s[idx]);

        solve(s, idx + 1, ans);
    }

    vector<string> letterCasePermutation(string s) {

        vector<string> ans;

        solve(s, 0, ans);

        return ans;
    }
};