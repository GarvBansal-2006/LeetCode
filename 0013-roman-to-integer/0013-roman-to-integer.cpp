class Solution {
    int value(char c) {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        if (c == 'M')
            return 1000;
        return 0;
    }

public:
    int romanToInt(string s) {
        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = value(s[i]);
            int next = (i + 1 < s.size()) ? value(s[i + 1]) : 0;

            if (curr < next)
                total -= curr;
            else
                total += curr;
        }
        return total;
    }
};