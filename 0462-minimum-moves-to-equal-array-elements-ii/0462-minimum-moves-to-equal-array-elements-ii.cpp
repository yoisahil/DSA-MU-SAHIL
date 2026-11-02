class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int mid = n / 2;

        // Place the median at index mid (average O(n))
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int median = nums[mid];

        int moves = 0;
        for (int x : nums) {
            moves += abs(x - median);
        }
        return moves;
    }
};