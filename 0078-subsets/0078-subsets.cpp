/* 
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    
        int n = nums.size();

        int subsets = 1 << n;

        vector<vector<int>> ans;

        for (int num = 0; num < subsets; num++) {
            vector<int> subset;

            for (int i = 0; i < n; i++) {
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            ans.push_back(subset);
        }

        return ans;
    }
};
*/
class Solution {
public:

    void fun(vector<int>& nums, int n, int idx,
             vector<int>& temp, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        // Choice 1: Not take current element
        fun(nums, n, idx + 1, temp, ans);

        // Choice 2: Take current element
        temp.push_back(nums[idx]);
        fun(nums, n, idx + 1, temp, ans);
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> temp;

        fun(nums, n, 0, temp, ans);

        return ans;
    }
};

