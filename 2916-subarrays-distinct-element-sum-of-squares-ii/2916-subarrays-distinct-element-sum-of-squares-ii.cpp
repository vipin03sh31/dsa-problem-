class Solution {
    vector<long long> s1, s2, lz;
    void ap(int o, int len, long long v) {
        s2[o] += 2 * v * s1[o] + v * v * len;
        s1[o] += v * len;
        lz[o] += v;
    }
    void upd(int o, int l, int r, int a, int b) {
        if (a <= l && r <= b) { ap(o, r - l + 1, 1); return; }
        int m = (l + r) / 2;
        if (lz[o]) {
            ap(2 * o, m - l + 1, lz[o]);
            ap(2 * o + 1, r - m, lz[o]);
            lz[o] = 0;
        }
        if (a <= m) upd(2 * o, l, m, a, b);
        if (b > m) upd(2 * o + 1, m + 1, r, a, b);
        s1[o] = s1[2 * o] + s1[2 * o + 1];
        s2[o] = s2[2 * o] + s2[2 * o + 1];
    }
public:
    int sumCounts(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        s1.assign(4 * n, 0); s2.assign(4 * n, 0); lz.assign(4 * n, 0);
        unordered_map<int, int> last;
        long long ans = 0;
        for (int j = 0; j < n; j++) {
            int p = last.count(nums[j]) ? last[nums[j]] : -1;
            upd(1, 0, n - 1, p + 1, j);
            last[nums[j]] = j;
            ans = (ans + s2[1]) % MOD;
        }
        return ans;
    }
};