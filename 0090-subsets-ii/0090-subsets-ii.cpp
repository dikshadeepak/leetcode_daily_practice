/*class Solution {
public:

    void solve(vector<int>& nums, int idx,
               vector<int>& temp,
               set<vector<int>>& st) {

        // Base case
        if (idx == nums.size()) {
            st.insert(temp);
            return;
        }

        // DON'T PICK
        solve(nums, idx + 1, temp, st);

        // PICK
        temp.push_back(nums[idx]);

        solve(nums, idx + 1, temp, st);

        // BACKTRACK
        temp.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        set<vector<int>> st;
        vector<int> temp;

        solve(nums, 0, temp, st);

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};
*/
class Solution {
public:

    void solve(vector<int>& nums, int idx,
               vector<int>& temp,
               vector<vector<int>>& ans) {

        // Every temp is a valid subset
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {

            // Skip duplicate choices
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            // PICK
            temp.push_back(nums[i]);

            solve(nums, i + 1, temp, ans);

            // BACKTRACK
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);

        return ans;
    }
};