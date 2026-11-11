class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        auto calc = [&](long long x) -> long long {
            return x * costBoth
                 + max(0LL, (long long)need1 - x) * cost1
                 + max(0LL, (long long)need2 - x) * cost2;
        };

        long long ans = calc(0);
        ans = min(ans, calc(need1));
        ans = min(ans, calc(need2));
        return ans;
    }
};