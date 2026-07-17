class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x) {
            int r = x % 10;
            ans = ans * 10 + r;
            x = x / 10;

            if (ans > INT_MAX || ans < INT_MIN) {
                return 0;
            }
        }
        return (int)ans;
    }
};
