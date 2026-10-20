class Solution {

    bool check(vector<int>& nums, int start, int k) {
        int cnt = 0;
        for (int i = 0; i < k; i++) {
            if (nums[start + i] > nums[start + (i + 1) % k])
                cnt++;
        }
        return cnt <= 1;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;
            int prevMax = 0;

            for (int start = 0; start < n; start += k) {
                if (!check(nums, start, k)) {
                    ok = false;
                    break;
                }

                int mn = *min_element(nums.begin() + start,
                                      nums.begin() + start + k);
                int mx = *max_element(nums.begin() + start,
                                      nums.begin() + start + k);

                if (mn < prevMax) {
                    ok = false;
                    break;
                }
                prevMax = mx;
            }

            if (ok)
                sum += k;
        }
        return sum;
    }
};