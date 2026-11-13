class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;          // prefix-max "records" of window [l, r], front = l
        long long cost = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            // add nums[l] at the left
            while (!dq.empty() && nums[dq.front()] <= nums[l]) {
                int j = dq.front();
                dq.pop_front();
                int nxt = dq.empty() ? r + 1 : dq.front();
                // elements in [j, nxt) now have prefix max nums[l]
                cost += (long long)(nums[l] - nums[j]) * (nxt - j);
            }
            dq.push_front(l);

            // shrink from the right until cost <= k
            while (cost > k) {
                if (dq.back() == r) {
                    dq.pop_back();
                } else {
                    cost -= nums[dq.back()] - nums[r];
                }
                r--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};