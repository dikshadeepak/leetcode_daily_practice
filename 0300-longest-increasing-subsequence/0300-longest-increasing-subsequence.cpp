/*class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int prev) {

        if (idx == nums.size())
            return 0;

        // DON'T PICK
        int notPick =
            solve(nums, idx + 1, prev);

        // PICK
        int pick = 0;

        if (prev == -1 ||
            nums[idx] > nums[prev]) {

            pick =
                1 + solve(nums,
                          idx + 1,
                          idx);
        }

        return max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {

        return solve(nums, 0, -1);
    }
};
*/
class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int prev,
              vector<vector<int>>& dp) {

        if (idx == nums.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int notPick =
            solve(nums,
                  idx + 1,
                  prev,
                  dp);

        int pick = 0;

        if (prev == -1 ||
            nums[idx] > nums[prev]) {

            pick =
                1 + solve(nums,
                          idx + 1,
                          idx,
                          dp);
        }

        return dp[idx][prev + 1] =
            max(pick, notPick);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(nums, 0, -1, dp);
    }
};