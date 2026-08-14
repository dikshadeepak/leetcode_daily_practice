class Solution {
public:

    int solve(int pos, int n, vector<bool>& used) {

        // All positions filled
        if (pos > n)
            return 1;

        int count = 0;

        for (int num = 1; num <= n; num++) {

            if (!used[num] &&
                (num % pos == 0 ||
                 pos % num == 0)) {

                // PICK
                used[num] = true;

                count += solve(pos + 1, n, used);

                // BACKTRACK
                used[num] = false;
            }
        }

        return count;
    }

    int countArrangement(int n) {

        vector<bool> used(n + 1, false);

        return solve(1, n, used);
    }
};