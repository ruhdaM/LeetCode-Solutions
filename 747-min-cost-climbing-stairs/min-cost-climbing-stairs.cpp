class Solution {
    int solve(vector<int>& cost, int k, vector<int>& dp) {
        if (k == 0)
            return cost[0];
        if (k == 1)
            return cost[1];

        if (dp[k] != -1)
            return dp[k];

        return dp[k] = cost[k] +
                       min(solve(cost, k - 1, dp), solve(cost, k - 2, dp));
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);

        return min(solve(cost, n - 1, dp), solve(cost, n - 2, dp));
    }
};