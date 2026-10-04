class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0; // minimum possible number of open '('
        int hi = 0; // maximum possible number of open '('

        for (char c : s) {
            if (c == '(') {
                lo++;
                hi++;
            } else if (c == ')') {
                lo--;
                hi--;
            } else { // '*' can be '(', ')' or empty
                lo--;
                hi++;
            }

            // Too many ')' even if every '*' acts as '('
            if (hi < 0) return false;

            // lo can't go below 0 (extra '*' treated as empty)
            if (lo < 0) lo = 0;
        }

        // Valid if zero open parentheses is achievable
        return lo == 0;
    }
};