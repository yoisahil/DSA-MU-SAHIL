class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1};
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    // If findFirst is true, returns the leftmost index of target, else the rightmost.
    // Returns -1 if target is not present.
    int findBound(vector<int>& nums, int target, bool findFirst) {
        int low = 0, high = (int)nums.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                ans = mid;
                // Keep searching toward the side we care about
                if (findFirst) high = mid - 1;
                else low = mid + 1;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};