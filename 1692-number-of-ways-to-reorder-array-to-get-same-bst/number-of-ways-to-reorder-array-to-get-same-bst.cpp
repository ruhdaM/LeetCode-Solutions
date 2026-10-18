class Solution {
public:
    using ll = long long;
    ll MOD = 1e9 + 7;

    vector<vector<ll>> C;

    ll countWays(vector<int>& nums) {
        int n = nums.size();

        if (n < 3)
            return 1;

        vector<int> left, right;

        for (int i = 1; i < n; ++i) {
            (nums[i] < nums[0] ? left : right).push_back(nums[i]);
        }

        ll ways = countWays(left) * countWays(right) % MOD;

        return ways * C[n - 1][left.size()] % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        C.assign(n + 1, {});

        for (int i = 0; i <= n; i++) {
            C[i].assign(i + 1, 1);

            for (int j = 1; j < i; j++) {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }

        return (countWays(nums) - 1 + MOD) % MOD;
    }
};