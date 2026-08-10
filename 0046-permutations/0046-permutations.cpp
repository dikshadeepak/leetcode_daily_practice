class Solution {
public:
    void solve(vector<int>& nums, int idx,
               vector<int>& temp,
               vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every element from idx onwards
        for (int i = idx; i < nums.size(); i++) {

            // INCLUDE:
            // Put nums[i] at the current position
            swap(nums[idx], nums[i]);

            temp.push_back(nums[idx]);

            solve(nums, idx + 1, temp, ans);

            // BACKTRACK:
            temp.pop_back();

            // Undo the swap
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> temp;

        solve(nums, 0, temp, ans);

        return ans;
    }
};