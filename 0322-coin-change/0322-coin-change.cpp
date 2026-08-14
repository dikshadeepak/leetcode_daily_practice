class Solution {
public:

    int solve(vector<int>& coins, int idx, int amount,
              vector<vector<int>>& dp) {

        // Base case
        if (amount == 0)
            return 0;

        if (idx == coins.size())
            return 1e9;

        // Already calculated
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        // DON'T PICK
        int notPick = solve(coins, idx + 1, amount, dp);

        // PICK
        int pick = 1e9;

        if (coins[idx] <= amount) {
            pick = 1 + solve(coins, idx, amount - coins[idx], dp);
        }

        // Store answer
        return dp[idx][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(coins, 0, amount, dp);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};