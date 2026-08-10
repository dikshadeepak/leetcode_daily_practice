class Solution {
public:
    void fun(vector<int>& a, int n, int idx, vector<int>& diary,
             int sum, vector<vector<int>>& res, int target) {

        // Base case
        if (idx == n) {
            if (sum == target) {
                res.push_back(diary);
            }
            return;
        }

        // Take current element
        if (sum + a[idx] <= target) {
            diary.push_back(a[idx]);
            sum = sum + a[idx];

            // Stay at same index because we can take
            // the same element multiple times
            fun(a, n, idx, diary, sum, res, target);

            // Backtrack
            diary.pop_back();
            sum = sum - a[idx];
        }

        // Don't take current element
        fun(a, n, idx + 1, diary, sum, res, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<vector<int>> res;
        vector<int> diary;

        fun(candidates, n, 0, diary, 0, res, target);

        return res;
    }
};