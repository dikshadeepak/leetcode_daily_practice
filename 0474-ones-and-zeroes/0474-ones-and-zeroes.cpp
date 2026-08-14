/*class Solution {
public:

    int solve(vector<string>& strs,
              int idx,
              int m,
              int n) {

        // No strings left
        if (idx == strs.size())
            return 0;

        int zero = 0;
        int one = 0;

        // Count 0s and 1s
        for (char ch : strs[idx]) {
            if (ch == '0')
                zero++;
            else
                one++;
        }

        // DON'T PICK
        int notPick = solve(strs, idx + 1, m, n);

        // PICK
        int pick = 0;

        if (zero <= m && one <= n) {

            pick = 1 + solve(
                strs,
                idx + 1,
                m - zero,
                n - one
            );
        }

        return max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        return solve(strs, 0, m, n);
    }
};
*/
class Solution {
public:

    int solve(vector<string>& strs,
              int idx,
              int m,
              int n,
              vector<vector<vector<int>>>& dp) {

        // Base case
        if (idx == strs.size())
            return 0;

        // Already calculated
        if (dp[idx][m][n] != -1)
            return dp[idx][m][n];

        int zero = 0;
        int one = 0;

        for (char ch : strs[idx]) {
            if (ch == '0')
                zero++;
            else
                one++;
        }

        // DON'T PICK
        int notPick = solve(
            strs,
            idx + 1,
            m,
            n,
            dp
        );

        // PICK
        int pick = 0;

        if (zero <= m && one <= n) {

            pick = 1 + solve(
                strs,
                idx + 1,
                m - zero,
                n - one,
                dp
            );
        }

        return dp[idx][m][n] = max(pick, notPick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {

        int size = strs.size();

        vector<vector<vector<int>>> dp(
            size,
            vector<vector<int>>(
                m + 1,
                vector<int>(n + 1, -1)
            )
        );

        return solve(strs, 0, m, n, dp);
    }
};
