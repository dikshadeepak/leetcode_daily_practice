
//1st by n2 complexity finding all the subaaray and checking for the each subarray.
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int mask = 0;
        int left = 0;
        int ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            
            // Remove elements until nums[right]
            // has no common set bit
            while ((mask & nums[right]) != 0) {
                mask = mask ^ nums[left];
                left++;
            }
            
            // Add current number
            mask = mask | nums[right];
            
            // Length of current nice subarray
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};