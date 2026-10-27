class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 1; i < n; i++) {
            string res;

            int j = 0;

            while (j < s.length()) {
                char digit = s[j];
                int cnt = 0;

                while (j < s.length() && s[j] == digit) {
                    ++j;
                    ++cnt;
                }

                res += to_string(cnt);
                res += digit;
            }

            s = res;
        }

        return s;
    }
};