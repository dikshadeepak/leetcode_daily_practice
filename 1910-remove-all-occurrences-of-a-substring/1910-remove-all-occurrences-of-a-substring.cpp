class Solution {
public:
    string removeOccurrences(string s, string part) {

        int pos = s.find(part);

        // Base case
        if (pos == string::npos)
            return s;

        // Remove the occurrence
        s.erase(pos, part.length());

        // Recursively remove remaining occurrences
        return removeOccurrences(s, part);
    }
};