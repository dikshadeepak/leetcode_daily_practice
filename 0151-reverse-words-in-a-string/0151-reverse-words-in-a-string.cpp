class Solution {
public:

    // Reverse characters from index start to end
    void reverse(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {

        int n = s.length();

        // Step 1: Remove extra spaces
        int j = 0;

        for (int i = 0; i < n; i++) {

            // Skip spaces
            if (s[i] == ' ')
                continue;

            // Add one space before every word except first
            if (j != 0)
                s[j++] = ' ';

            // Copy the complete word
            while (i < n && s[i] != ' ') {
                s[j++] = s[i];
                i++;
            }
        }

        // Remove unused characters
        s.resize(j);

        // Step 2: Reverse every individual word
        int start = 0;

        for (int end = 0; end <= s.length(); end++) {

            if (end == s.length() || s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1;
            }
        }

        // Step 3: Reverse the complete string
        reverse(s, 0, s.length() - 1);

        return s;
    }
};