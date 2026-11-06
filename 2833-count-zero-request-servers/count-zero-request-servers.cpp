class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        for (auto& lg : logs) {
            swap(lg[0], lg[1]);
        }
        sort(logs.begin(), logs.end());

        int m = queries.size();
        vector<pair<int, int>> qs;
        for (int i = 0; i < m; i++) {
            qs.push_back({queries[i], i});
        }
        sort(qs.begin(), qs.end());

        vector<int> cnt(n + 1), ans(m);
        int active = 0, l = 0, r = 0;

        for (auto [q, id] : qs) {
            while (r < logs.size() && logs[r][0] <= q) {
                if (cnt[logs[r++][1]]++ == 0)
                    active++;
            }

            while (logs.size() > l && logs[l][0] < q - x) {
                if (--cnt[logs[l++][1]] == 0)
                    active--;
            }

            ans[id] = n - active;
        }

        return ans;
    }
};