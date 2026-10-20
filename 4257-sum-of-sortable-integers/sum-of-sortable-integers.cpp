class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;
            int prevMax = 0;

            for (int l = 0; l < n && ok; l += k) {
                int drops = 0, mn = INT_MAX, mx = INT_MIN;

                for (int j = l; j < l + k; j++) {
                    int next = (j + 1 < l + k) ? nums[j + 1] : nums[l];

                    if (nums[j] > next)
                        drops++;

                    mn = min(mn, nums[j]);
                    mx = max(mx, nums[j]);
                }

                if (drops > 1 || mn < prevMax)
                    ok = false;
                    
                prevMax = mx;
            }

            if (ok)
                ans += k;
        }
        return ans;
    }
};