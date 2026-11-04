class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        const long long INF = LLONG_MAX / 4;

        // ---- Step 1: cost of every window of size x ----
        multiset<int> lo, hi;          // lo = smaller half (size ceil(x/2)), hi = larger half
        long long sumLo = 0, sumHi = 0;
        int loSize = (x + 1) / 2;

        auto rebalance = [&]() {
            while ((int)lo.size() > loSize) {
                auto it = prev(lo.end());
                sumLo -= *it; sumHi += *it;
                hi.insert(*it);
                lo.erase(it);
            }
            while ((int)lo.size() < loSize && !hi.empty()) {
                auto it = hi.begin();
                sumHi -= *it; sumLo += *it;
                lo.insert(*it);
                hi.erase(it);
            }
        };
        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) { lo.insert(v); sumLo += v; }
            else { hi.insert(v); sumHi += v; }
            rebalance();
        };
        auto remove = [&](int v) {
            if (v <= *lo.rbegin()) { lo.erase(lo.find(v)); sumLo -= v; }
            else { hi.erase(hi.find(v)); sumHi -= v; }
            rebalance();
        };

        int m = n - x + 1;
        vector<long long> cost(m);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) remove(nums[i - x]);
            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sumLo
                                + sumHi - med * (long long)hi.size();
            }
        }

        // ---- Step 2: DP over positions and number of subarrays ----
        vector<long long> prev(n + 1, 0), cur(n + 1, INF);  // prev = dp[j-1]
        for (int j = 1; j <= k; j++) {
            fill(cur.begin(), cur.end(), INF);
            for (int i = 1; i <= n; i++) {
                cur[i] = cur[i - 1];
                if (i >= x && prev[i - x] < INF)
                    cur[i] = min(cur[i], prev[i - x] + cost[i - x]);
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};