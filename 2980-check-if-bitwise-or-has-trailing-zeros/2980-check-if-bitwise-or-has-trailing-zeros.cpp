class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 1;

        while (i < n - 1) {
            if ((nums[i] | nums[j]) % 2 == 0)
                return true;

            j++;

            if (j == n) {
                i++;
                j = i + 1;
            }
        }

        return false;
    }
};