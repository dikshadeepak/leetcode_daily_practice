/*class Solution {
public:

    bool solve(vector<int>& nums,
               int idx, int target) {

        if (target == 0)
            return true;

        if (idx == nums.size())
            return false;

        // DON'T PICK
        bool notPick =
            solve(nums, idx + 1, target);

        // PICK
        bool pick = false;

        if (nums[idx] <= target) {

            pick =
                solve(nums,
                      idx + 1,
                      target - nums[idx]);
        }

        return pick || notPick;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        return solve(nums, 0, sum / 2);
    }
};
*/
class Solution {
public:

    bool solve(vector<int>& nums,
               int idx, int target,
               vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (idx == nums.size())
            return false;

        if (dp[idx][target] != -1)
            return dp[idx][target];

        bool notPick =
            solve(nums, idx + 1,
                  target, dp);

        bool pick = false;

        if (nums[idx] <= target) {

            pick =
                solve(nums,
                      idx + 1,
                      target - nums[idx],
                      dp);
        }

        return dp[idx][target] =
            pick || notPick;
    }

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(
            nums.size(),
            vector<int>(target + 1, -1)
        );

        return solve(nums, 0, target, dp);
    }
};
/*
class Solution {
public:

    bool canPartition(vector<int>& nums) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        int n = nums.size();

        vector<vector<bool>> dp(
            n + 1,
            vector<bool>(target + 1, false)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) {

            for (int t = 1; t <= target; t++) {

                bool notPick =
                    dp[i - 1][t];

                bool pick = false;

                if (nums[i - 1] <= t)
                    pick =
                        dp[i - 1]
                          [t - nums[i - 1]];

                dp[i][t] =
                    pick || notPick;
            }
        }

        return dp[n][target];
    }
};
*/