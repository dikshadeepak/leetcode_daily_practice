/*class Solution {
public:
    bool solve(int index, string &s, vector<string>& wordDict) {
        
        // Reached end of string
        if (index == s.size()) {
            return true;
        }

        // Try every word
        for (string word : wordDict) {
            
            int len = word.size();

            // Check if word fits
            if (index + len <= s.size() &&
                s.substr(index, len) == word) {
                
                // Take this word
                if (solve(index + len, s, wordDict)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(0, s, wordDict);
    }
};
*/
/*
class Solution {
public:
    bool solve(int index, string &s, vector<string>& wordDict,
               vector<int>& dp) {
        
        // Reached end
        if (index == s.size()) {
            return true;
        }

        // Already calculated
        if (dp[index] != -1) {
            return dp[index];
        }

        // Try every word
        for (string word : wordDict) {
            
            int len = word.size();

            if (index + len <= s.size() &&
                s.substr(index, len) == word) {
                
                if (solve(index + len, s, wordDict, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        vector<int> dp(n, -1);

        return solve(0, s, wordDict, dp);
    }
};
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();

        vector<bool> dp(n + 1, false);

        // Empty string can always be formed
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            
            for (string word : wordDict) {
                
                int len = word.size();

                if (i >= len &&
                    dp[i - len] &&
                    s.substr(i - len, len) == word) {
                    
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};