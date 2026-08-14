/*
class Solution {
public:

    int solve(vector<int>& nums, int idx) {

        if (idx >= nums.size())
            return 0;

        // DON'T PICK
        int notPick =
            solve(nums, idx + 1);

        // PICK
        int pick =
            nums[idx] +
            solve(nums, idx + 2);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        return solve(nums, 0);
    }
};

class Solution {
public:

    int solve(vector<int>& nums, int idx,
              vector<int>& dp) {

        if (idx >= nums.size())
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        // DON'T PICK
        int notPick =
            solve(nums, idx + 1, dp);

        // PICK
        int pick =
            nums[idx] +
            solve(nums, idx + 2, dp);

        return dp[idx] =
            max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, dp);
    }
};
class Solution {
public:

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp(n + 2, 0);

        for (int i = n - 1; i >= 0; i--) {

            int notPick = dp[i + 1];

            int pick =
                nums[i] + dp[i + 2];

            dp[i] = max(pick, notPick);
        }

        return dp[0];
    }
};
*/
class Solution {
public:

    int solve(vector<int>& nums, int idx,
              int prev, vector<vector<int>>& dp) {

        // Base case
        if (idx >= nums.size())
            return 0;

        // Already calculated
        if (dp[idx][prev] != -1)
            return dp[idx][prev];

        // DON'T PICK current house
        int notPick =
            solve(nums, idx + 1, 0, dp);

        int pick = 0;

        // PICK only if previous house was not robbed
        if (prev == 0) {

            pick =
                nums[idx] +
                solve(nums, idx + 1, 1, dp);
        }

        return dp[idx][prev] =
            max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        // dp[idx][prev]
        vector<vector<int>> dp(
            n,
            vector<int>(2, -1)
        );

        return solve(nums, 0, 0, dp);
    }
};