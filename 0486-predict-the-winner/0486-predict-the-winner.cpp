class Solution {
public:

    int solve(int l, int r, vector<int>& nums) {

        if (l == r)
            return nums[l];

        int left = nums[l] - solve(l + 1, r, nums);

        int right = nums[r] - solve(l, r - 1, nums);

        return max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {

        int n = nums.size();

        int scoreDifference = solve(0, n - 1, nums);

        return scoreDifference >= 0;
    }
};