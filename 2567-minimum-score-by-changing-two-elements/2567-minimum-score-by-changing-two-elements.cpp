class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return min({
            nums[n - 3] - nums[0],   // remove two largest
            nums[n - 2] - nums[1],   // remove one smallest, one largest
            nums[n - 1] - nums[2]    // remove two smallest
        });
    }
};