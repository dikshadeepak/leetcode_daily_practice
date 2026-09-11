class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            }
            else {
                int k = right;
                while (k > left && s[k] != s[left]) {
                    k--;
                }
                if (k == left) {

                    swap(s[k], s[k + 1]);
                    ans++;
                }
                else {
                    while (k < right) {
                        swap(s[k], s[k + 1]);
                        k++;
                        ans++;
                    }
                    left++;
                    right--;
                }
            }
        }

        return ans;
    }
};