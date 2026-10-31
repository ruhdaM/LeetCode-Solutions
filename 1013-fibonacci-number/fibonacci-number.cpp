class Solution {
    int fib(int n, vector<int>& dp) {
        if (n <= 1)
            return n;

        if (dp[n] != -1)
            return dp[n];

        dp[n] = fib(n - 1) + fib(n - 2);

        return dp[n];
    }

public:
    int fib(int n) {
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++) {
            dp[i] = -1;
        }

        return fib(n, dp);
    }
};