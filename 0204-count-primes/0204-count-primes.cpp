class Solution {
    bool isSet(const vector<unsigned int>& bits, int x) {
        return bits[x >> 5] & (1u << (x & 31));
    }

    void clearBit(vector<unsigned int>& bits, int x) {
        bits[x >> 5] &= ~(1u << (x & 31));
    }

public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<unsigned int> isPrime((n >> 5) + 1, ~0u);

        clearBit(isPrime, 0);
        clearBit(isPrime, 1);

        for (int i = 2; i * i < n; i++) {
            if (isSet(isPrime, i)) {
                for (int j = i * i; j < n; j += i) {
                    clearBit(isPrime, j);
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isSet(isPrime, i))
                count++;
        }
        return count;
    }
};