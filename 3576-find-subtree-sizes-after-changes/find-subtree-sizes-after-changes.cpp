
class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> ans(n, 1);
        vector<int> last(26, -1);

        function<void(int)> dfs = [&](int u) {
            int c = s[u] - 'a';

            int prev = last[c];
            last[c] = u;

            for (int v : adj[u]) {
                dfs(v);
            }

            last[c] = prev;

            if (u != 0) {
                int p = (prev != -1) ? prev : parent[u];
                ans[p] += ans[u];
            }
        };

        dfs(0);
        return ans;
    }
};
