class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {

            int temp = (1 << bit);

            int countOne = 0;
            int countZero = 0;

            for (int num : nums) {

                if ((num & temp) == 0)
                    countZero++;
                else
                    countOne++;
            }

            if (countOne % 3 == 1)
                result |= temp;
        }

        return result;
    }
};