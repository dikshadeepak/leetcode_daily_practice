/*class Solution {
public:
    bool solve(int index, int jump, vector<int>& stones) {

        if (index == stones.size() - 1) {
            return true;
        }

        for (int nextJump = jump - 1; nextJump <= jump + 1; nextJump++) {

            if (nextJump <= 0)
                continue;

            int nextPosition = stones[index] + nextJump;

            for (int i = index + 1; i < stones.size(); i++) {

                if (stones[i] == nextPosition) {

                    if (solve(i, nextJump, stones))
                        return true;
                }

                if (stones[i] > nextPosition)
                    break;
            }
        }

        return false;
    }

    bool canCross(vector<int>& stones) {

        if (stones[1] != 1)
            return false;

        return solve(1, 1, stones);
    }
};
*/
class Solution {
public:
    bool solve(int index, int jump,
               vector<int>& stones,
               unordered_map<long long, bool>& dp) {

        if (index == stones.size() - 1)
            return true;

        long long key = ((long long)index << 32) | jump;

        if (dp.find(key) != dp.end())
            return dp[key];

        for (int nextJump = jump - 1;
             nextJump <= jump + 1;
             nextJump++) {

            if (nextJump <= 0)
                continue;

            int nextPosition = stones[index] + nextJump;

            for (int i = index + 1; i < stones.size(); i++) {

                if (stones[i] == nextPosition) {

                    if (solve(i, nextJump, stones, dp))
                        return dp[key] = true;
                }

                if (stones[i] > nextPosition)
                    break;
            }
        }

        return dp[key] = false;
    }

    bool canCross(vector<int>& stones) {

        if (stones[1] != 1)
            return false;

        unordered_map<long long, bool> dp;

        return solve(1, 1, stones, dp);
    }
};