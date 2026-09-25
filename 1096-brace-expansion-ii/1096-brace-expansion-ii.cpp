class Solution {
public:
    vector<string> braceExpansionII(string expr) {
        int i = 0;
        set<string> res = parse(expr, i);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> parse(string& s, int& i) {
        vector<set<string>> groups;   // comma-separated alternatives
        set<string> cur = {""};       // current concatenation being built

        while (i < (int)s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;                              // skip '{'
                set<string> inner = parse(s, i);   // recurse
                i++;                              // skip matching '}'
                cur = merge(cur, inner);
            } else if (s[i] == ',') {
                groups.push_back(cur);
                cur = {""};
                i++;
            } else {
                int j = i;
                while (j < (int)s.size() && islower(s[j])) j++;
                string word = s.substr(i, j - i);
                set<string> wordSet = {word};
                cur = merge(cur, wordSet);
                i = j;
            }
        }
        groups.push_back(cur);

        set<string> result;
        for (auto& g : groups) result.insert(g.begin(), g.end());
        return result;
    }

    set<string> merge(set<string>& a, set<string>& b) {
        set<string> res;
        for (auto& x : a)
            for (auto& y : b)
                res.insert(x + y);
        return res;
    }
};