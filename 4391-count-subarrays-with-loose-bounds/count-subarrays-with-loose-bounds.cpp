class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] < minK || nums[r] > maxK)
                l = r + 1;

            else
                ans += r - l + 1;
        }

        return ans;
    }
};