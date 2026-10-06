class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;   // unmatched '(' so far
        int add = 0;    // ')' that had no match, so we need to add '('

        for (char c : s) {
            if (c == '(') {
                open++;
            } else {
                if (open > 0) open--;   // match with a previous '('
                else add++;             // unmatched ')'
            }
        }
        return open + add;  // leftover '(' need ')', unmatched ')' need '('
    }
};