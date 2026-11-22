class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        char prev = 'a';

        for(int i = 0; i < n; i++) {
            char curr = s[i];

            if(curr != prev) {
                if(curr == 'a' && prev == 'b') return false;
            }

            prev = curr;
        }

        return true;
    }
};