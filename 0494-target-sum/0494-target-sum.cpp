/*
class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int target) {

        if (idx == nums.size()) {

            if (target == 0)
                return 1;

            return 0;
        }

        int plus =
            solve(nums,
                  idx + 1,
                  target - nums[idx]);

        int minus =
            solve(nums,
                  idx + 1,
                  target + nums[idx]);

        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        return solve(nums, 0, target);
    }
};
*/
class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int target,
              vector<unordered_map<int,int>>& dp) {

        if (idx == nums.size())
            return target == 0;

        if (dp[idx].count(target))
            return dp[idx][target];

        int plus =
            solve(nums,
                  idx + 1,
                  target - nums[idx],
                  dp);

        int minus =
            solve(nums,
                  idx + 1,
                  target + nums[idx],
                  dp);

        return dp[idx][target] =
            plus + minus;
    }

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        vector<unordered_map<int,int>> dp(
            nums.size()
        );

        return solve(nums, 0, target, dp);
    }
};
/*
clean way by subset formation nd sum/minus
tabulation
class Solution {
public:

    int findTargetSumWays(vector<int>& nums,
                          int target) {

        int sum = 0;

        for (int x : nums)
            sum += x;

        if (abs(target) > sum)
            return 0;

        if ((sum + target) % 2 != 0)
            return 0;

        int required =
            (sum + target) / 2;

        vector<int> dp(required + 1, 0);

        dp[0] = 1;

        for (int x : nums) {

            for (int t = required;
                 t >= x;
                 t--) {

                dp[t] += dp[t - x];
            }
        }

        return dp[required];
    }
};
*/