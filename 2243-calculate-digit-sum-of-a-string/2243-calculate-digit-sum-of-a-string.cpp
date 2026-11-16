class Solution {
public:
    string digitSum(string s, int k) {
        while (s.length() > k) {
            string next = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                // sum digits of the group [i, i+k)
                for (int j = i; j < i + k && j < s.length(); j++) {
                    sum += s[j] - '0';
                }
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};