class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int need = 0;  // number of ')' still required to balance the open '('

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // If need is odd, the previous '(' has only one ')' so far.
                // Insert one ')' to complete it before starting a new '('.
                if (need % 2 == 1) {
                    insertions++;
                    need--;
                }
                need += 2;
            } else {
                need--;
                if (need == -1) {
                    // Extra ')' with no matching '(': insert a '('
                    // which now needs one more ')' to be complete.
                    insertions++;
                    need = 1;
                }
            }
        }

        return insertions + need;
    }
};