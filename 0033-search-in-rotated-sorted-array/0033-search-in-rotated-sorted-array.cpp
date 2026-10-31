class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            // Left half [low..mid] is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;   // target lies in the sorted left half
                } else {
                    low = mid + 1;
                }
            }
            // Otherwise the right half [mid..high] is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;    // target lies in the sorted right half
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};