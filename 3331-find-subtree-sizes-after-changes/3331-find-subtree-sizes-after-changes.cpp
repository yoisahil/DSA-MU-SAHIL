class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        vector<int> newParent(n, -1), size(n, 1), prevLast(n, -1), idx(n, 0);
        int last[26];
        fill(last, last + 26, -1);

        vector<int> st;
        st.push_back(0);
        // enter root
        prevLast[0] = last[s[0] - 'a'];
        last[s[0] - 'a'] = 0;

        while (!st.empty()) {
            int x = st.back();
            if (idx[x] < (int)children[x].size()) {
                int c = children[x][idx[x]++];
                int ch = s[c] - 'a';
                // enter child
                prevLast[c] = last[ch];
                newParent[c] = (last[ch] != -1) ? last[ch] : parent[c];
                last[ch] = c;
                st.push_back(c);
            } else {
                // exit x
                int ch = s[x] - 'a';
                last[ch] = prevLast[x];
                if (x != 0) size[newParent[x]] += size[x];
                st.pop_back();
            }
        }
        return size;
    }
};