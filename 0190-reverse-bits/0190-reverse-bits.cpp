class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {

            // Take last bit of n
            int bit = n & 1;

            // Shift ans left
            ans = (ans << 1) | bit;

            // Remove last bit from n
            n = n >> 1;
        }

        return ans;
    }
};