class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) < n) LOG++;
        vector<vector<int>> up(LOG + 1, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n), tout(n);

        // iterative DFS
        int timer = 1; // BIT is 1-indexed
        vector<pair<int,int>> st;
        st.push_back({0, 0});
        up[0][0] = 0;
        tin[0] = timer++;
        while (!st.empty()) {
            auto &[u, idx] = st.back();
            if (idx < (int)g[u].size()) {
                int v = g[u][idx++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                tin[v] = timer++;
                st.push_back({v, 0});
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int k = 1; k <= LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k <= LOG; k++)
                if (diff >> k & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }
            return up[0][a];
        };

        // BIT: range xor update, point query
        vector<int> bit(n + 2, 0);
        auto add = [&](int i, int val) {
            for (; i <= n + 1; i += i & -i) bit[i] ^= val;
        };
        auto query = [&](int i) {
            int r = 0;
            for (; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto rangeXor = [&](int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        };

        for (int i = 0; i < n; i++)
            rangeXor(tin[i], tout[i], 1 << (s[i] - 'a'));

        vector<bool> ans;
        for (auto &q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u; char c;
                ss >> u >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (delta) rangeXor(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = query(tin[u]) ^ query(tin[v]) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};