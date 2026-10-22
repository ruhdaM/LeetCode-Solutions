class Solution {
    bool check(vector<int>& nums, int zero, int dir) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int idx = (zero + i * dir + n) % n;

            if (nums[idx] != i)
                return false;
        }

        return true;
    }

public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int z = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                z = i;
                break;
            }
        }

        int ans = INT_MAX;

        if (check(nums, z, 1)) {
            ans = min(ans, z);
            ans = min(ans, n - z + 2);
        }

        if (check(nums, z, -1)) {
            ans = min(ans, z + 2);
            ans = min(ans, n - z);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};