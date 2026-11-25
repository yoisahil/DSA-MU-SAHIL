class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<map<int,int>> nxt(1);
        vector<int> link(1, -1), len(1, 0), cnt(1, 0);
        int last = 0;

        for (int x : nums) {
            int cur = nxt.size();
            nxt.emplace_back();
            link.push_back(0);
            len.push_back(len[last] + 1);
            cnt.push_back(1);              // real (non-clone) state

            int p = last;
            while (p != -1 && !nxt[p].count(x)) {
                nxt[p][x] = cur;
                p = link[p];
            }
            if (p == -1) {
                link[cur] = 0;
            } else {
                int q = nxt[p][x];
                if (len[p] + 1 == len[q]) {
                    link[cur] = q;
                } else {
                    int clone = nxt.size();
                    nxt.push_back(nxt[q]);
                    link.push_back(link[q]);
                    len.push_back(len[p] + 1);
                    cnt.push_back(0);      // clone has no own occurrence
                    while (p != -1 && nxt[p][x] == q) {
                        nxt[p][x] = clone;
                        p = link[p];
                    }
                    link[q] = link[cur] = clone;
                }
            }
            last = cur;
        }

        // propagate occurrence counts up suffix links (longest len first)
        int sz = nxt.size();
        vector<int> order(sz);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return len[a] > len[b];
        });
        for (int v : order)
            if (link[v] > 0) cnt[link[v]] += cnt[v];

        int ans = n;
        for (int v = 1; v < sz; v++)
            if (cnt[v] == 1)
                ans = min(ans, len[link[v]] + 1);
        return ans;
    }
};