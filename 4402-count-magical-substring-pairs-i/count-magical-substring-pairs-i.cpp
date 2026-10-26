class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.length();
        int ans = 0;

        for (int j = 0; j < n - 1; j++) {
            vector<int> cnt(27, 0);
            vector<bool> seen(26, false);
            int d = 0;

            for (int k = j + 1; k < n; k++) {
                if (!seen[s[k] - 'a']) {
                    seen[s[k] - 'a'] = true;
                    d++;
                }
                
                cnt[d]++;
            }

            vector<bool> seen2(26, false);
            d = 0;

            for (int i = j; i >= 0; i--) {
                if (!seen2[s[i] - 'a']) {
                    seen2[s[i] - 'a'] = true;
                    d++;
                }
                
                ans += cnt[d];
            }
        }

        return ans;
    }
};