class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            // Check if previous prefix sum exists
            int needed = prefixSum - k;

            if (mp.find(needed) != mp.end()) {
                count += mp[needed];
            }
            mp[prefixSum]++;
        }

        return count;
    }
};