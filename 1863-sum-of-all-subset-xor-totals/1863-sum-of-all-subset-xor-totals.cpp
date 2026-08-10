class Solution {
public:
    int solve(vector<int>& nums, int idx,
              vector<int>& temp, int currXor) {

        // Base case
        if (idx == nums.size())
            return currXor;

        // Include
        temp.push_back(nums[idx]);

        int include = solve(nums, idx + 1,  temp, currXor ^ nums[idx]);

        // Backtrack
        temp.pop_back();

        // Exclude
        int exclude = solve(nums, idx + 1, temp, currXor);

        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        vector<int> temp;

        return solve(nums, 0, temp, 0);
    }
};