class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2, n = nums1.size();
        vector<long long> d(n + 1, 0);
        for (int i = 0; i < n; i++) d[i] = abs(nums1[i] - nums2[i]);
        sort(d.begin(), d.end(), greater<long long>());
        for (long long i = 0; i < n; i++) {
            long long w = i + 1, c = (d[i] - d[i + 1]) * w;
            if (k >= c) { k -= c; continue; }
            long long q = k / w, r = k % w, v = d[i] - q;
            long long res = r * (v - 1) * (v - 1) + (w - r) * v * v;
            for (long long j = i + 1; j < n; j++) res += d[j] * d[j];
            return res;
        }
        return 0;
    }
};