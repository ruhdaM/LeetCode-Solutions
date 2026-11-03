class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;

        while (true) {
            int mn = INT_MAX, mx = INT_MIN, idx = 0;

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] < mn) {
                    mn = nums[i];
                    idx = i;
                }

                mx = max(mx, nums[i]);
            }

            if (mn == mx)
                break;

            nums[idx]++;
            ans++;
        }

        return ans;
    }
};