class Solution {
public:
    using ll = long long;
    int MOD = 1e9 + 7;

    ll power(ll a, ll b) {
        if (b == 0)
            return 1;

        ll half = power(a, b / 2);

        ll res = half * half % MOD;

        if (b % 2 == 1)
            res = res * a % MOD;

        return res;
    }

    int countGoodNumbers(ll n) {
        ll even = (n + 1) / 2;
        ll odd = n / 2;

        ll a = power(5, even);
        ll b = power(4, odd);

        return a * b % MOD;
    }
};