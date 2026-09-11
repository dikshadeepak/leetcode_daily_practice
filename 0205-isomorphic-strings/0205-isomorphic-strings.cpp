class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        int map1[256] = {0};
        int map2[256] = {0};

        for (int i = 0; i < s.length(); i++) {

            char a = s[i];
            char b = t[i];

            if (map1[a] == 0 && map2[b] == 0) {

                map1[a] = b;
                map2[b] = a;

            }
            else {

                if (map1[a] != b || map2[b] != a) {
                    return false;
                }
            }
        }

        return true;
    }
};