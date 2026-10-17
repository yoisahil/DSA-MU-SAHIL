class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // {digitSum, value, originalIndex}
        vector<tuple<int, int, int>> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i], i});
        }

        // sort by digit sum, then by value
        sort(arr.begin(), arr.end());

        // arr[i] should end up at position i, so it currently sits at get<2>(arr[i])
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || get<2>(arr[i]) == i) continue;

            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = get<2>(arr[j]);
                cycleLen++;
            }
            swaps += cycleLen - 1;
        }

        return swaps;
    }
};