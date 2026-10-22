class Solution {
    using ll = long long;

public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        bool negative = (dividend < 0) ^ (divisor < 0);

        ll a = abs((ll)dividend);
        ll b = abs((ll)divisor);

        ll result = 0;

        while (a >= b) {
            ll temp = b;
            ll multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            result += multiple;
        }

        if (negative)
            result = -result;

        return result;
    }
};