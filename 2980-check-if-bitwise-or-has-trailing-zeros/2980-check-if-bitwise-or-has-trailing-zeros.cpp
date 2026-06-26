class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int even = 0;

        for (int x : nums) {
            if ((x & 1) == 0)
                even++;
        }

        return even >= 2;
    }
};