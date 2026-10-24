class Solution {
    int day(string& s) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int m = stoi(s.substr(0, 2)), d = stoi(s.substr(3, 2));

        for (int i = 0; i < m - 1; i++) {
            d += days[i];
        }

        return d;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {
        int aA = day(arriveAlice), lA = day(leaveAlice);
        int aB = day(arriveBob), lB = day(leaveBob);

        int count = 0;

        for (int d = 1; d <= 365; d++) {
            if (d >= aA && d <= lA && d >= aB && d <= lB)
                count++;
        }

        return count;
    }
};