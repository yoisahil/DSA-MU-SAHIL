class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (is_sorted(s.begin(), s.end())) return 0;
        if (n == 2) return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // sort s[1..n-1] or s[0..n-2]
        if (s[0] == mn || s[n - 1] == mx) return 1;

        // s[0] strictly greater than all others AND s[n-1] strictly smaller than all others
        bool firstUniqueMax = (s[0] == mx) && count(s.begin(), s.end(), mx) == 1;
        bool lastUniqueMin  = (s[n - 1] == mn) && count(s.begin(), s.end(), mn) == 1;
        if (firstUniqueMax && lastUniqueMin) return 3;

        return 2;
    }
};