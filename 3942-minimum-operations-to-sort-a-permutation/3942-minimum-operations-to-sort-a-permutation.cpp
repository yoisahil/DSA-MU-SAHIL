class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        // state id: type 0 -> a[i] = (i + p) % n ; type 1 -> a[i] = (p - i) mod n
        // id = type * n + p
        auto matches = [&](const vector<int>& a, int type, int p) {
            for (int i = 0; i < n; i++) {
                int v = (type == 0) ? (i + p) % n : (((p - i) % n) + n) % n;
                if (a[i] != v) return false;
            }
            return true;
        };

        vector<int> sorted(n);
        for (int i = 0; i < n; i++) sorted[i] = i;

        vector<int> dist(2 * n, -1);
        queue<int> q;
        // multi-source: every state representation equal to nums
        for (int t = 0; t < 2; t++) {
            int p = nums[0];  // p is forced by the first element
            if (matches(nums, t, p)) {
                int id = t * n + p;
                if (dist[id] == -1) {
                    dist[id] = 0;
                    q.push(id);
                }
            }
        }
        if (q.empty()) return -1;

        while (!q.empty()) {
            int id = q.front(); q.pop();
            int t = id / n, p = id % n;

            if (matches(sorted, t, p)) return dist[id];

            int next[2];
            // rotate left by one
            next[0] = (t == 0) ? t * n + (p + 1) % n
                               : t * n + (p - 1 + n) % n;
            // reverse
            next[1] = (t == 0) ? 1 * n + (n - 1 + p) % n
                               : 0 * n + (p + 1) % n;

            for (int nx : next) {
                if (dist[nx] == -1) {
                    dist[nx] = dist[id] + 1;
                    q.push(nx);
                }
            }
        }
        return -1;
    }
};