/*class Solution {
public:
    int solve(int i, string &s) {
        
        // Reached the end
        if (i == s.size())
            return 1;
        
        // Cannot start with 0
        if (s[i] == '0')
            return 0;
        
        // Pick one digit
        int pick = solve(i + 1, s);
        
        // Pick two digits
        int notPick = 0;
        
        if (i + 1 < s.size()) {
            
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            
            if (num >= 10 && num <= 26) {
                notPick = solve(i + 2, s);
            }
        }
        
        return pick + notPick;
    }

    int numDecodings(string s) {
        return solve(0, s);
    }
};
*/
/*
class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        
        if (i == s.size())
            return 1;
        
        if (s[i] == '0')
            return 0;
        
        if (dp[i] != -1)
            return dp[i];
        
        // Pick one digit
        int pick = solve(i + 1, s, dp);
        
        // Pick two digits
        int notPick = 0;
        
        if (i + 1 < s.size()) {
            
            int num = (s[i] - '0') * 10
                    + (s[i + 1] - '0');
            
            if (num >= 10 && num <= 26) {
                notPick = solve(i + 2, s, dp);
            }
        }
        
        return dp[i] = pick + notPick;
    }

    int numDecodings(string s) {
        
        int n = s.size();
        
        vector<int> dp(n, -1);
        
        return solve(0, s, dp);
    }
};
*/
class Solution {
public:
    int numDecodings(string s) {
        
        int n = s.size();
        
        vector<int> dp(n + 1, 0);
        
        // Empty string has one valid way
        dp[n] = 1;
        
        for (int i = n - 1; i >= 0; i--) {
            
            // Cannot decode a string starting with 0
            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }
            
            // Pick one digit
            dp[i] = dp[i + 1];
            
            // Pick two digits
            if (i + 1 < n) {
                
                int num = (s[i] - '0') * 10
                        + (s[i + 1] - '0');
                
                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        
        return dp[0];
    }
};