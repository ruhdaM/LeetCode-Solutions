
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int mn = INT_MAX;

        for (auto& it : items)
            mn = min(mn, it[1]);

        vector<int> dp(budget + 1, 0);

        for (int b = 0; b <= budget; b++)
            dp[b] = b / mn;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];
            int gain = 0;

            for (int j = 0; j < n; j++) {
                if (items[j][0] % factor == 0)
                    gain++;
            }

            for (int b = budget; b >= price; b--) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        return dp[budget];
    }
};
