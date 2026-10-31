class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int n = s.size();
        int m = words.size();
        int len = words[0].size();
        int total = m * len;
        if (n < total) return res;

        // Frequency of each word we need to match
        unordered_map<string, int> need;
        for (auto& w : words) need[w]++;

        // Each offset handles words aligned at positions offset, offset+len, ...
        for (int offset = 0; offset < len; offset++) {
            int left = offset;
            int count = 0;
            unordered_map<string, int> seen;

            for (int right = offset; right + len <= n; right += len) {
                string word = s.substr(right, len);

                if (need.count(word)) {
                    seen[word]++;
                    count++;

                    // Too many copies of this word: shrink window from the left
                    while (seen[word] > need[word]) {
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        count--;
                        left += len;
                    }

                    // Window contains exactly all the words
                    if (count == m) {
                        res.push_back(left);

                        // Slide forward by one word to look for the next match
                        string leftWord = s.substr(left, len);
                        seen[leftWord]--;
                        count--;
                        left += len;
                    }
                } else {
                    // Word not in the list: reset the window
                    seen.clear();
                    count = 0;
                    left = right + len;
                }
            }
        }

        return res;
    }
};