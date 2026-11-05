class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int count = 0;

        for (int x : arr1) {
            // first element >= x - d
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            // if no such element, or it's > x + d, then no element lies in [x-d, x+d]
            if (it == arr2.end() || *it > x + d) {
                count++;
            }
        }
        return count;
    }
};