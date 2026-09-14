/*class Solution {
public:
    int solve(int target, vector<int>& nums, int i) {
        
        if (target == 0)
            return 1;
        
        if (target < 0)
            return 0;
        
        if (i == nums.size())
            return 0;
        
        // Pick current number
        int pick = solve(target - nums[i], nums, 0);
        
        // Not pick current number
        int notPick = solve(target, nums, i + 1);
        
        return pick + notPick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        return solve(target, nums, 0);
    }
};
*/
/*
class Solution {
public:
    int solve(int target, vector<int>& nums, vector<int>& dp) {
        
        if (target == 0)
            return 1;
        
        if (target < 0)
            return 0;
        
        if (dp[target] != -1)
            return dp[target];
        
        int ans = 0;
        
        for (int x : nums) {
            
            if (x <= target) {
                ans += solve(target - x, nums, dp);
            }
        }
        
        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target + 1, -1);
        
        return solve(target, nums, dp);
    }
};
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        
        const long long LIMIT = INT_MAX;
        
        for (int t = 1; t <= target; t++) {
            
            for (int x : nums) {
                
                if (x <= t) {
                    
                    // Prevent overflow
                    if (dp[t] > LIMIT - dp[t - x]) {
                        dp[t] = LIMIT;
                    }
                    else {
                        dp[t] += dp[t - x];
                    }
                }
            }
        }
        
        return (int)dp[target];
    }
};