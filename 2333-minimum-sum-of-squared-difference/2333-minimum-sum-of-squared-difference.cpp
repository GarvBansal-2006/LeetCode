class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        map<long long int, long long int> mp;

        for (int i = 0; i < nums1.size(); i++)
            mp[-1LL * abs(nums1[i] - nums2[i])]++;

        k1 += k2;

        while (!mp.empty() && k1) {
            long long int a = -(*mp.begin()).first;
            long long int b = (*mp.begin()).second;
            mp.erase(mp.begin());

            int parbo = k1 / b;

            if (mp.empty()) {
                if (parbo < a) {
                    a -= parbo;
                    mp[-a] += b - (k1 % b);
                    mp[-(a - 1)] += (k1 % b);
                }

                k1 = 0;
            } else {
                long long int aa = -(*mp.begin()).first;
                long long int dis = a - aa;

                if (dis <= parbo) {
                    k1 -= (dis * b);
                    mp[-aa] += b;
                } else {
                    k1 -= (parbo * b);
                    mp[-(a - parbo)] += (b - k1);
                    mp[-(a - parbo - 1)] += k1;
                    k1 = 0;
                }
            }
        }

        long long int ans = 0;

        for (auto& it : mp)
            ans += (it.first * it.first * it.second);

        return ans;
    }
};