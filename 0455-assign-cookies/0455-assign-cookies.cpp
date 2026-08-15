class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0;
        int j = 0;

        while (i < g.size() && j < s.size()) {
            
            // Current cookie can satisfy current child
            if (s[j] >= g[i]) {
                i++;
            }

            // Move to next cookie
            j++;
        }

        return i;
    }
};