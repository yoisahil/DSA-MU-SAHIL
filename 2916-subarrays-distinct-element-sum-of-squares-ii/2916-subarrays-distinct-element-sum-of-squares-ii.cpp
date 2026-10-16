class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> sum, sq, lz;

    void apply(int o, int l, int r, long long k) {
        long long len = r - l + 1;
        sq[o] = (sq[o] + 2 * k % MOD * sum[o] % MOD + k * k % MOD * len) % MOD;
        sum[o] = (sum[o] + k * len) % MOD;
        lz[o] = (lz[o] + k) % MOD;
    }

    void push(int o, int l, int r) {
        if (lz[o]) {
            int m = (l + r) / 2;
            apply(o * 2, l, m, lz[o]);
            apply(o * 2 + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
    }

    void update(int o, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(o, l, r, 1);
            return;
        }
        push(o, l, r);
        int m = (l + r) / 2;
        if (ql <= m) update(o * 2, l, m, ql, qr);
        if (qr > m) update(o * 2 + 1, m + 1, r, ql, qr);
        sum[o] = (sum[o * 2] + sum[o * 2 + 1]) % MOD;
        sq[o] = (sq[o * 2] + sq[o * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int prev = last.count(nums[j]) ? last[nums[j]] : -1;
            update(1, 0, n - 1, prev + 1, j);
            ans = (ans + sq[1]) % MOD;
            last[nums[j]] = j;
        }
        return ans;
    }
};