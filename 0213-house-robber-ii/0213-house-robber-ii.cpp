/*
class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int end) {

        if (idx > end)
            return 0;

        int notPick =
            solve(nums, idx + 1, end);

        int pick =
            nums[idx] +
            solve(nums, idx + 2, end);

        return max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        int case1 =
            solve(nums, 0, n - 2);

        int case2 =
            solve(nums, 1, n - 1);

        return max(case1, case2);
    }
};
*/
class Solution {
public:

    int solve(vector<int>& nums,
              int idx, int end,
              vector<int>& dp) {

        if (idx > end)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int notPick =
            solve(nums, idx + 1, end, dp);

        int pick =
            nums[idx] +
            solve(nums, idx + 2, end, dp);

        return dp[idx] =
            max(pick, notPick);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 =
            solve(nums, 0, n - 2, dp1);

        int case2 =
            solve(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};
/*
class Solution {
public:

    int solve(vector<int>& nums,
              int start, int end) {

        vector<int> dp(nums.size() + 2, 0);

        for (int i = end; i >= start; i--) {

            dp[i] =
                max(dp[i + 1],
                    nums[i] + dp[i + 2]);
        }

        return dp[start];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        return max(
            solve(nums, 0, n - 2),
            solve(nums, 1, n - 1)
        );
    }
};
*/