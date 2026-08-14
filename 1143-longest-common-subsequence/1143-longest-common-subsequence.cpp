/*
class Solution {
public:

    int solve(string& text1,
              string& text2,
              int i, int j) {

        if (i == text1.size() ||
            j == text2.size())
            return 0;

        if (text1[i] == text2[j]) {

            return 1 +
                   solve(text1,
                         text2,
                         i + 1,
                         j + 1);
        }

        int skip1 =
            solve(text1,
                  text2,
                  i + 1,
                  j);

        int skip2 =
            solve(text1,
                  text2,
                  i,
                  j + 1);

        return max(skip1, skip2);
    }

    int longestCommonSubsequence(
        string text1,
        string text2) {

        return solve(text1,
                     text2,
                     0,
                     0);
    }
};
*/
class Solution {
public:

    int solve(string& text1,
              string& text2,
              int i, int j,
              vector<vector<int>>& dp) {

        if (i == text1.size() ||
            j == text2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j]) {

            return dp[i][j] =
                1 + solve(text1,
                          text2,
                          i + 1,
                          j + 1,
                          dp);
        }

        int skip1 =
            solve(text1,
                  text2,
                  i + 1,
                  j,
                  dp);

        int skip2 =
            solve(text1,
                  text2,
                  i,
                  j + 1,
                  dp);

        return dp[i][j] =
            max(skip1, skip2);
    }

    int longestCommonSubsequence(
        string text1,
        string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n,
            vector<int>(m, -1)
        );

        return solve(text1,
                     text2,
                     0,
                     0,
                     dp);
    }
};
/*
class Solution {
public:

    int longestCommonSubsequence(
        string text1,
        string text2) {

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(m + 1, 0)
        );

        for (int i = n - 1;
             i >= 0;
             i--) {

            for (int j = m - 1;
                 j >= 0;
                 j--) {

                if (text1[i] == text2[j]) {

                    dp[i][j] =
                        1 + dp[i + 1][j + 1];

                } else {

                    dp[i][j] =
                        max(dp[i + 1][j],
                            dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};
*/