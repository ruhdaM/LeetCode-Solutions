class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq, pos;
            int k = 0, valid = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (freq[x] == 0)
                    pos[x] = ++k;

                if (freq[x] == pos[x])
                    valid--;
                
                freq[x]++;
                
                if (freq[x] == pos[x])
                    valid++;

                if (valid == k)
                    ans++;
            }
        }

        return (int)ans;
    }
};