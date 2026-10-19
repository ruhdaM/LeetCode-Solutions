class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int less = 0, equal = 0;

        for (int num : nums) {
            if (num < target)
                less++;
            else if (num == target)
                equal++;
        }

        vector<int> indices(equal);

        for (int i = 0; i < equal; i++) {
            indices[i] = less + i;
        }

        return indices;
    }
};