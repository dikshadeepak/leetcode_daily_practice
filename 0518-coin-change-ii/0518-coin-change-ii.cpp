/*class Solution {
public:

    int solve(vector<int>& coins,
              int idx, int amount) {

        if (amount == 0)
            return 1;

        if (idx == coins.size())
            return 0;

        // DON'T PICK
        int notPick =
            solve(coins,
                  idx + 1,
                  amount);

        // PICK
        int pick = 0;

        if (coins[idx] <= amount) {

            pick =
                solve(coins,
                      idx,
                      amount - coins[idx]);
        }

        return pick + notPick;
    }

    int change(int amount,
               vector<int>& coins) {

        return solve(coins, 0, amount);
    }
};
*/
class Solution {
public:

    int solve(vector<int>& coins,
              int idx, int amount,
              vector<vector<int>>& dp) {

        if (amount == 0)
            return 1;

        if (idx == coins.size())
            return 0;

        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notPick =
            solve(coins,
                  idx + 1,
                  amount,
                  dp);

        int pick = 0;

        if (coins[idx] <= amount) {

            pick =
                solve(coins,
                      idx,
                      amount - coins[idx],
                      dp);
        }

        return dp[idx][amount] =
            pick + notPick;
    }

    int change(int amount,
               vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        return solve(coins,
                     0,
                     amount,
                     dp);
    }
};
/*
class Solution {
public:

    int change(int amount,
               vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(amount + 1, 0)
        );

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int idx = n - 1;
             idx >= 0;
             idx--) {

            for (int amt = 1;
                 amt <= amount;
                 amt++) {

                int notPick =
                    dp[idx + 1][amt];

                int pick = 0;

                if (coins[idx] <= amt)
                    pick =
                        dp[idx]
                          [amt - coins[idx]];

                dp[idx][amt] =
                    pick + notPick;
            }
        }

        return dp[0][amount];
    }
};
*/