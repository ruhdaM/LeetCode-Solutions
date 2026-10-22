class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int z = 0;
        while (nums[z] != 0) {
            z++;
        }

        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {

            if (nums[(z + i) % n] != i)
                inc = false;

            if (nums[(z - i + n) % n] != i)
                dec = false;
        }

        if (inc)
            return min(z, n - z + 2);

        if (dec)
            return min(z + 2, n - z);

        return -1;
    }
};